#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#include "configuracao.h"
#include "mapa.h"

typedef struct Nodo {
    int info[TAMANHO_GENOMA];
    int fitness;
    struct Nodo* prox;
} TNo;

typedef struct {
    TNo* cabeca;
    int tamanho;
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

/**
 * * Função que adiciona um indivíduo à população.
 * * @param lista ponteiro para a população
 * @param individuo ponteiro para o indivíduo
 */
void adicionar_individuo(Populacao* lista, TNo* individuo);

/**
 * * Função que libera a memória da lista de indivíduos.
 * * @param lista ponteiro para a população
 */
void liberar_lista(Populacao* lista);

#endif