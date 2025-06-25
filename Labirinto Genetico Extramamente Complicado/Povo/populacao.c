#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "populacao.h"

#define TORNEIO 3

static void adicionar_individuo(Populacao* pop, Individuo* ind) {
    Nodo* novo = malloc(sizeof(Nodo));
    novo->ind = ind;
    novo->prox = pop->cabeca;
    pop->cabeca = novo;
    pop->tamanho++;
}

static Individuo* selecao_torneio(Populacao* pop) {
    Individuo* melhor = NULL;
    for (int i = 0; i < TORNEIO; i++) {
        int idx = rand() % pop->tamanho;
        Nodo* atual = pop->cabeca;
        for (int j = 0; j < idx && atual; j++) {
            atual = atual->prox;
        }
        if (atual && (!melhor || atual->ind->fitness > melhor->fitness)) {
            melhor = atual->ind;
        }
    }
    return melhor;
}

float calcular_desvio_padrao_tamanho_genoma(Populacao* lista) {
    if (lista->tamanho == 0) return 0.0;
    float soma = 0.0, media, desvio_padrao = 0.0;
    Nodo* atual = lista->cabeca;

    while (atual != NULL) {
        soma += atual->ind->tamanho_genoma;
        atual = atual->prox;
    }

    media = soma / lista->tamanho;
    atual = lista->cabeca;

    while (atual != NULL) {
        desvio_padrao += pow(atual->ind->tamanho_genoma - media, 2);
        atual = atual->prox;
    }

    return sqrt(desvio_padrao / lista->tamanho);
}

static void crossover(Individuo* pai1, Individuo* pai2, Individuo* filho1, Individuo* filho2, Labirinto* lab, Populacao* pop) {
    int distancia_manhattan = abs(lab->inicio_x - lab->fim_x) + abs(lab->inicio_y - lab->fim_y);
    int tamanho1 = (pai1->tamanho_genoma + pai2->tamanho_genoma) / 2 + (rand() % 3 - 1);
    int tamanho2 = (pai1->tamanho_genoma + pai2->tamanho_genoma) / 2 + (rand() % 3 - 1);

    // Se você tiver uma função calcular_desvio_padrao_tamanho_genoma, use pop como argumento
    if (tamanho1 < calcular_desvio_padrao_tamanho_genoma(pop))
        tamanho1 = distancia_manhattan + rand() % (distancia_manhattan * 2);
    if (tamanho2 < calcular_desvio_padrao_tamanho_genoma(pop))
        tamanho2 = distancia_manhattan + rand() % (distancia_manhattan * 2);

    filho1->tamanho_genoma = tamanho1;
    filho1->genoma = (int*)malloc(tamanho1 * sizeof(int));

    filho2->tamanho_genoma = tamanho2;
    filho2->genoma = (int*)malloc(tamanho2 * sizeof(int));

    for (int i = 0; i < filho1->tamanho_genoma; i++) {
    if (i < pai1->tamanho_genoma && i < pai2->tamanho_genoma) {
        // Sorteia aleatoriamente o gene do pai1 ou pai2
        if (rand() % 2 == 0)
            filho1->genoma[i] = pai1->genoma[i];
        else
            filho1->genoma[i] = pai2->genoma[i];
    } else if (i < pai1->tamanho_genoma) {
        filho1->genoma[i] = pai1->genoma[i];
    } else if (i < pai2->tamanho_genoma) {
        filho1->genoma[i] = pai2->genoma[i];
    } else {
        // Se ultrapassou os dois tamanhos, insere gene aleatório
        filho1->genoma[i] = rand() % 4;
    }
}

for (int i = 0; i < filho2->tamanho_genoma; i++) {
    if (i < pai1->tamanho_genoma && i < pai2->tamanho_genoma) {
        // Sorteia aleatoriamente o gene do pai2 ou pai1 (ordem invertida)
        if (rand() % 2 == 0)
            filho2->genoma[i] = pai2->genoma[i];
        else
            filho2->genoma[i] = pai1->genoma[i];
    } else if (i < pai2->tamanho_genoma) {
        filho2->genoma[i] = pai2->genoma[i];
    } else if (i < pai1->tamanho_genoma) {
        filho2->genoma[i] = pai1->genoma[i];
    } else {
        // Se ultrapassou os dois tamanhos, insere gene aleatório
        filho2->genoma[i] = rand() % 4;
    }
}
}

static void mutacao(Individuo* ind, float taxa) {
    for (int i = 0; i < ind->tamanho_genoma; i++) {
        if ((float)rand() / RAND_MAX < taxa) {
            ind->genoma[i] = rand() % 4;
        }
    }
}

Populacao* criar_populacao(int tamanho, Labirinto* lab, const char* versao_geracao) {
    Populacao* pop = malloc(sizeof(Populacao));
    pop->cabeca = NULL;
    pop->tamanho = 0;

    int dist = abs(lab->inicio_x - lab->fim_x) + abs(lab->inicio_y - lab->fim_y);

    for (int i = 0; i < tamanho; i++) {
        int tam_genoma = dist + rand() % (dist * 2);
        Individuo* ind = criar_individuo(tam_genoma);

        if (strcmp(versao_geracao, "inteligente") == 0)
            inicializar_genoma_inteligente(ind, lab);
        else
            inicializar_genoma_aleatorio(ind);

        calcular_fitness(ind, lab);
        adicionar_individuo(pop, ind);
    }

    return pop;
}

void nova_geracao(Populacao* pop, Labirinto* lab, const char* modo) {
    Populacao* nova = malloc(sizeof(Populacao));
    nova->cabeca = NULL;
    nova->tamanho = 0;

    Individuo* elite = obter_melhor_individuo(pop);
    adicionar_individuo(nova, copiar_individuo(elite));

    while (nova->tamanho < pop->tamanho) {
        Individuo* p1 = selecao_torneio(pop);
        Individuo* p2 = selecao_torneio(pop);

        int tam1 = (p1->tamanho_genoma + p2->tamanho_genoma) / 2 + (rand() % 3 - 1);
        int tam2 = (p1->tamanho_genoma + p2->tamanho_genoma) / 2 + (rand() % 3 - 1);

        Individuo* f1 = criar_individuo(tam1);
        Individuo* f2 = criar_individuo(tam2);

        crossover(p1, p2, f1, f2, lab, pop);
        mutacao(f1, 0.02f);
        mutacao(f2, 0.02f);

        calcular_fitness(f1, lab);
        calcular_fitness(f2, lab);

        adicionar_individuo(nova, f1);
        if (nova->tamanho < pop->tamanho)
            adicionar_individuo(nova, f2);
        else
            liberar_individuo(f2);
    }

    liberar_populacao(pop);
    pop->cabeca = nova->cabeca;
    pop->tamanho = nova->tamanho;
    free(nova);
}

Individuo* obter_melhor_individuo(Populacao* pop) {
    if (pop->cabeca == NULL) return NULL;
    Nodo* atual = pop->cabeca;
    Individuo* melhor = atual->ind;
    while (atual != NULL) {
        if (atual->ind->fitness > melhor->fitness)
            melhor = atual->ind;
        atual = atual->prox;
    }
    return melhor;
}

void liberar_populacao(Populacao* pop) {
    Nodo* atual = pop->cabeca;
    while (atual) {
        Nodo* temp = atual;
        atual = atual->prox;
        liberar_individuo(temp->ind);
        free(temp);
    }
    pop->cabeca = NULL;
    pop->tamanho = 0;
}
