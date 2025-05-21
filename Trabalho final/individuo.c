#include "individuo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void calcular_fitness(TNo* ind) {
    int x = inicio_x, y = inicio_y;
    int colisoes = 0;

    for (int i = 0; i < TAMANHO_GENOMA; i++) {
        int novo_x = x, novo_y = y;
        switch (ind->info[i]) {
            case 0: novo_y--; break; // Cima
            case 1: novo_y++; break; // Baixo
            case 2: novo_x--; break; // Esquerda
            case 3: novo_x++; break; // Direita
        }

        if (novo_x < 0 || novo_x >= ALTURA || novo_y < 0 || novo_y >= LARGURA || labirinto[novo_x][novo_y] == '#') {
            colisoes++;
            break;
        }

        x = novo_x;
        y = novo_y;

        if (x == fim_x && y == fim_y) {
            break;
        }
    }

    int distancia = abs(x - fim_x) + abs(y - fim_y);
    ind->fitness = 1000 - distancia - (colisoes * 100);
}

void simular_caminho(TNo* ind) {
    char copia_labirinto[ALTURA][LARGURA];
    memcpy(copia_labirinto, labirinto, sizeof(labirinto));

    int x = inicio_x, y = inicio_y;
    for (int i = 0; i < TAMANHO_GENOMA; i++) {
        int novo_x = x, novo_y = y;
        switch (ind->info[i]) {
            case 0: novo_y--; break;
            case 1: novo_y++; break;
            case 2: novo_x--; break;
            case 3: novo_x++; break;
        }

        if (novo_x < 0 || novo_x >= ALTURA || novo_y < 0 || novo_y >= LARGURA || copia_labirinto[novo_x][novo_y] == '#') {
            break;
        }

        x = novo_x;
        y = novo_y;

        if (copia_labirinto[x][y] != 'S' && copia_labirinto[x][y] != 'E') {
            copia_labirinto[x][y] = '.';
        }

        if (x == fim_x && y == fim_y) {
            break;
        }
    }

    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            printf("%c", copia_labirinto[i][j]);
        }
        printf("\n");
    }
}