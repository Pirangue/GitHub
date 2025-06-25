#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"

Config* carregar_config(const char* caminho) {
    Config* cfg = (Config*)malloc(sizeof(Config));
    if (!cfg) {
        perror("Erro ao alocar memória para Config");
        exit(1);
    }
    FILE* arq = fopen(caminho, "r");
    if (!arq) {
        perror("Erro ao abrir arquivo de configuração");
        exit(1);
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arq)) {
        char chave[50], valor[200];

        if (linha[0] == '#' || linha[0] == ';' || linha[0] == '\n' || linha[0] == '[')
            continue;

        if (sscanf(linha, "%[^=]=%[^\n]", chave, valor) == 2) {
            // Remover espaços em branco
            while (*chave == ' ') memmove(chave, chave + 1, strlen(chave));
            while (*valor == ' ') memmove(valor, valor + 1, strlen(valor));
            char* fim = chave + strlen(chave) - 1;
            while (*fim == ' ' && fim > chave) *fim-- = '\0';
            fim = valor + strlen(valor) - 1;
            while (*fim == ' ' && fim > valor) *fim-- = '\0';

            if (strcmp(chave, "tamanho_populacao") == 0)
                cfg->tamanho_populacao = atoi(valor);
            else if (strcmp(chave, "taxa_mutacao") == 0)
                cfg->taxa_mutacao = atof(valor);
            else if (strcmp(chave, "max_geracoes") == 0)
                cfg->max_geracoes = atoi(valor);
            else if (strcmp(chave, "versao_geracao") == 0)
                strncpy(cfg->versao_geracao, valor, sizeof(cfg->versao_geracao));
            else if (strcmp(chave, "arquivo_labirinto") == 0)
                strncpy(cfg->arquivo_mapa, valor, sizeof(cfg->arquivo_mapa));
            else if (strcmp(chave, "arquivo_saida_log") == 0)
                strncpy(cfg->arquivo_saida_log, valor, sizeof(cfg->arquivo_saida_log));
        }
    }

    fclose(arq);
    return cfg;
}

void liberar_config(Config* cfg) {
    // Nenhum campo alocado dinamicamente por enquanto.
}
