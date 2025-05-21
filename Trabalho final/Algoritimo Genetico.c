#include "Algoritimo Genetico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void inicializar_populacao(Populacao* lista) {
    for (int i = 0; i < POPULACAO; i++) {
        TNo* individuo = (TNo*)malloc(sizeof(TNo));
        for (int j = 0; j < TAMANHO_GENOMA; j++) {
            individuo->info[j] = rand() % 4;
        }
        calcular_fitness(individuo);
        adicionar_individuo(lista, individuo);
    }
}

TNo* selecao_torneio(Populacao* lista) {
    TNo* melhor = NULL;
    for (int i = 0; i < TORNEIO; i++) {
        int indice = rand() % lista->tamanho;
        TNo* candidato = lista->cabeca;
        for (int j = 0; j < indice; j++) {
            candidato = candidato->prox;
        }
        if (melhor == NULL || candidato->fitness > melhor->fitness) {
            melhor = candidato;
        }
    }
    return melhor;
}

void crossover(TNo* pai1, TNo* pai2, TNo* filho) {
    int ponto_corte = rand() % TAMANHO_GENOMA;
    for (int i = 0; i < ponto_corte; i++) {
        filho->info[i] = pai1->info[i];
    }
    for (int i = ponto_corte; i < TAMANHO_GENOMA; i++) {
        filho->info[i] = pai2->info[i];
    }
}

void mutacao(TNo* ind) {
    for (int i = 0; i < TAMANHO_GENOMA; i++) {
        if ((float)rand() / RAND_MAX < TAXA_MUTACAO) {
            ind->info[i] = rand() % 4;
        }
    }
}

void nova_geracao(Populacao* lista) {
    Populacao nova_lista = {NULL, 0};

    // Preservar o melhor indivíduo
    TNo* atual = lista->cabeca;
    TNo* melhor = atual;
    while (atual != NULL) {
        if (atual->fitness > melhor->fitness) {
            melhor = atual;
        }
        atual = atual->prox;
    }
    TNo* melhor_copia = (TNo*)malloc(sizeof(TNo));
    *melhor_copia = *melhor;
    adicionar_individuo(&nova_lista, melhor_copia);

    // Gerar novos indivíduos
    for (int i = 1; i < POPULACAO; i++) {
        TNo* pai1 = selecao_torneio(lista);
        TNo* pai2 = selecao_torneio(lista);
        TNo* filho = (TNo*)malloc(sizeof(TNo));
        crossover(pai1, pai2, filho);
        mutacao(filho);
        calcular_fitness(filho);
        adicionar_individuo(&nova_lista, filho);
    }

    liberar_lista(lista);
    *lista = nova_lista;
}