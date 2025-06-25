#ifndef POPULACAO_H
#define POPULACAO_H

#include "../Povo/individuo.h"
#include "../Labirinto/labirinto.h"

typedef struct Nodo {
    Individuo* ind;
    struct Nodo* prox;
} Nodo;

typedef struct {
    Nodo* cabeca;
    int tamanho;
} Populacao;

/**
 * Cria uma nova população de indivíduos.
 * @param tamanho Tamanho da população.
 * @param lab Ponteiro para o labirinto onde os indivíduos serão avaliados.
 * @param modo Modo de inicialização dos indivíduos: "aleatoria" ou "inteligente".
 * @return Um ponteiro para a estrutura Populacao alocada dinamicamente.
 *         Retorna NULL em caso de erro de alocação de memória.
 */
Populacao* criar_populacao(int tamanho, Labirinto* lab, const char* modo);

/**
 * libera a memória alocada para uma população.
 * @param pop Ponteiro para a população a ser liberada.
 */
void liberar_populacao(Populacao* pop);

/**
 * obtém o melhor indivíduo de uma população com base no fitness.
 * @param pop Ponteiro para a população da qual o melhor indivíduo será obtido.
 * @return Um ponteiro para o melhor indivíduo encontrado, ou NULL se a população estiver vazia.
 */
Individuo* obter_melhor_individuo(Populacao* pop);

/**
 * gera uma nova população a partir de uma população existente,
 * aplicando seleção, crossover e mutação.
 * @param pop Ponteiro para a população atual.
 * @param lab Ponteiro para o labirinto onde os indivíduos serão avaliados.
 * @param modo Modo de geração: "aleatoria" ou "inteligente".
 * @note A nova população substitui a antiga.
 */
void nova_geracao(Populacao* pop, Labirinto* lab, const char* modo);

#endif
