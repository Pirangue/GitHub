#include "Algoritimo Genetico.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void inicializar_populacao(Populacao* pop) {
    for (int i = 0; i < POPULACAO; i++) {
        for (int j = 0; j < TAMANHO_GENOMA; j++) {
            pop->individuos[i].info[j] = rand() % 4;
        }
        calcular_fitness(&pop->individuos[i]);
    }
}

TNo selecao_torneio(Populacao* pop) {
    TNo melhor = pop->individuos[rand() % POPULACAO];
    for (int i = 1; i < TORNEIO; i++) {
        TNo candidato = pop->individuos[rand() % POPULACAO];
        if (candidato.fitness > melhor.fitness) {
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

void nova_geracao(Populacao* pop) {
    Populacao nova_populacao;

    // Preservar o melhor indivíduo
    TNo melhor = pop->individuos[0];
    for (int i = 1; i < POPULACAO; i++) {
        if (pop->individuos[i].fitness > melhor.fitness) {
            melhor = pop->individuos[i];
        }
    }
    nova_populacao.individuos[0] = melhor;

    // Gerar novos indivíduos
    for (int i = 1; i < POPULACAO; i++) {
        TNo pai1 = selecao_torneio(pop);
        TNo pai2 = selecao_torneio(pop);
        TNo filho;
        crossover(&pai1, &pai2, &filho);
        mutacao(&filho);
        calcular_fitness(&filho);
        nova_populacao.individuos[i] = filho;
    }

    *pop = nova_populacao;
}