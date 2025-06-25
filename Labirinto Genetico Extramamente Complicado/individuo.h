#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#include "labirinto.h"

typedef struct Individuo {
    int* genoma;
    int tamanho_genoma;
    int fitness;
} Individuo;

Individuo* criar_individuo(int tamanho);
void liberar_individuo(Individuo* ind);

void inicializar_genoma_aleatorio(Individuo* ind);
void inicializar_genoma_inteligente(Individuo* ind, Labirinto* lab);

void calcular_fitness(Individuo* ind, Labirinto* lab);
void escrever_genoma_textual(Individuo* ind, FILE* saida);
void imprimir_caminho_individuo(Individuo* ind, Labirinto* lab);
Individuo* copiar_individuo(Individuo* original);

#endif
