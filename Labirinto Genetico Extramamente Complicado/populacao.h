#ifndef POPULACAO_H
#define POPULACAO_H

#include "individuo.h"
#include "labirinto.h"

typedef struct Nodo {
    Individuo* ind;
    struct Nodo* prox;
} Nodo;

typedef struct {
    Nodo* cabeca;
    int tamanho;
} Populacao;

Populacao* criar_populacao(int tamanho, Labirinto* lab, const char* modo);
void liberar_populacao(Populacao* pop);

Individuo* obter_melhor_individuo(Populacao* pop);
void nova_geracao(Populacao* pop, Labirinto* lab, const char* modo);

#endif
