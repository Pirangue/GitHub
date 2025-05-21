#ifndef MAPA_H
#define MAPA_H

#include "configuracao.h"

extern char labirinto[ALTURA][LARGURA];
extern int inicio_x, inicio_y, fim_x, fim_y;

/**
 * * Função que imprime o labirinto na tela.
 * * A função percorre o labirinto e imprime cada caractere.
 */
void imprimir_labirinto();

/**
 * * Função que encontra as posições de início e fim no labirinto.
 * * A função percorre o labirinto e armazena as coordenadas de início e fim
 */
void encontrar_posicoes();

#endif