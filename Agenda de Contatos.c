#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 50

typedef struct {
    char nome[128];
    char telefone[15];
} Contato;

Contato agenda[MAX_CONTATOS];
int total_contatos = 0;
int alteracoes = 0;

void carregar_contatos(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        printf("Arquivo nao encontrado. Criando novo...\n");
        return;
    }

    total_contatos = 0;
    while (fscanf(arquivo, "%[^,], %[^\n]\n", agenda[total_contatos].nome, agenda[total_contatos].telefone) == 2) {
        total_contatos++;
        if (total_contatos >= MAX_CONTATOS) break;
    }

    fclose(arquivo);
    printf("Contatos carregados com sucesso!\n");
}

void salvar_contatos(const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (!arquivo) {
        perror("Erro ao salvar o arquivo");
        return;
    }

    for (int i = 0; i < total_contatos; i++) {
        fprintf(arquivo, "%s, %s\n", agenda[i].nome, agenda[i].telefone);
    }

    fclose(arquivo);
    alteracoes = 0;
    printf("Contatos salvos com sucesso!\n");
}

void adicionar_contato() {
    if (total_contatos >= MAX_CONTATOS) {
        printf("Agenda cheia! Nao e possível adicionar mais contatos.\n");
        return;
    }

    printf("Digite o nome: ");
    scanf(" %[^\n]", agenda[total_contatos].nome);
    printf("Digite o telefone: ");
    scanf(" %[^\n]", agenda[total_contatos].telefone);

    total_contatos++;
    alteracoes = 1;
    printf("Contato adicionado com sucesso!\n");
}

void listar_contatos() {
    printf("\nContatos na agenda:\n");
    for (int i = 0; i < total_contatos; i++) {
        printf("%d. %s - %s\n", i + 1, agenda[i].nome, agenda[i].telefone);
    }
    if (total_contatos == 0) {
        printf("A agenda esta vazia.\n");
    }
    printf("\n");
}

void deletar_contato() {
    char nome[128];
    printf("Digite o nome do contato a ser deletado: ");
    scanf(" %[^\n]", nome);

    int encontrado = 0;
    for (int i = 0; i < total_contatos; i++) {
        if (strcmp(agenda[i].nome, nome) == 0) {
            encontrado = 1;
            for (int j = i; j < total_contatos - 1; j++) {
                agenda[j] = agenda[j + 1];
            }
            total_contatos--;
            alteracoes = 1;
            printf("Contato deletado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Contato nao encontrado.\n");
    }
}

int main() {
    const char *nome_arquivo = "contatos.csv";

    carregar_contatos(nome_arquivo);

    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Cadastro de novo contato\n");
        printf("2. Imprimir agenda em tela\n");
        printf("3. Deletar um contato\n");
        printf("4. Salvar em arquivo (formato CSV)\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_contato();
                break;
            case 2:
                listar_contatos();
                break;
            case 3:
                deletar_contato();
                break;
            case 4:
                salvar_contatos(nome_arquivo);
                break;
            case 5:
                if (alteracoes) {
                    printf("Salvando alteracoes antes de sair...\n");
                    salvar_contatos(nome_arquivo);
                }
                printf("Saindo...\n");
                break;
            default:
                printf("Opçao invalida.\n");
        }
    } while (opcao != 5);

    return 0;
}
