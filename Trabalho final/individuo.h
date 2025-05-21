#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#include "configuracao.h"
#include "mapa.h"

typedef struct {
    int info[TAMANHO_GENOMA];
    int fitness;
} TNo;

typedef struct {
    TNo individuos[POPULACAO];
} Populacao;

/**
 * * Função que calcula o fitness de um indivíduo.
 * * A função percorre o labirinto e calcula a distância do indivíduo até o fim.
 * @param ind ponteiro para o indivíduo
 */
void calcular_fitness(TNo* ind);

/**
 * * Função que simula o caminho de um indivíduo no labirinto.
 * * A função percorre o labirinto e marca o caminho do indivíduo.
 * * @param ind ponteiro para o indivíduo
 */
void simular_caminho(TNo* ind);

#endif