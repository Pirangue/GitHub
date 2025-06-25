#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "individuo.h"

Individuo* criar_individuo(int tamanho) {
    Individuo* ind = malloc(sizeof(Individuo));
    ind->genoma = malloc(tamanho * sizeof(int));
    ind->tamanho_genoma = tamanho;
    ind->fitness = 0;
    // inicialize outros campos se houver
    return ind;
}

void liberar_individuo(Individuo* ind) {
    if (ind->genoma) free(ind->genoma);
    free(ind);
}

void inicializar_genoma_aleatorio(Individuo* ind) {
    for (int i = 0; i < ind->tamanho_genoma; i++) {
        ind->genoma[i] = rand() % 4; // 0 = cima, 1 = baixo, 2 = esquerda, 3 = direita
    }
}

// Versão mais inteligente: só move para onde é válido
void inicializar_genoma_inteligente(Individuo* ind, Labirinto* lab) {
    int x = lab->inicio_x;
    int y = lab->inicio_y;

    for (int i = 0; i < ind->tamanho_genoma; i++) {
        int tentativas = 0;
        int mov;
        int novo_x, novo_y;
        do {
            mov = rand() % 4;
            novo_x = x + (mov == 1) - (mov == 0);
            novo_y = y + (mov == 3) - (mov == 2);
            tentativas++;
        } while (!posicao_valida(lab, novo_x, novo_y) && tentativas < 10);

        ind->genoma[i] = mov;
        if (posicao_valida(lab, novo_x, novo_y)) {
            x = novo_x;
            y = novo_y;
        }
    }
}

void calcular_fitness(Individuo* ind, Labirinto* lab) {
    int x = lab->inicio_x;
    int y = lab->inicio_y;
    int colisoes = 0;
    int ult_mov = -1;

    for (int i = 0; i < ind->tamanho_genoma; i++) {
        int mov = ind->genoma[i];
        int novo_x = x + (mov == 1) - (mov == 0);
        int novo_y = y + (mov == 3) - (mov == 2);

        if ((ult_mov == 0 && mov == 1) || (ult_mov == 1 && mov == 0) ||
            (ult_mov == 2 && mov == 3) || (ult_mov == 3 && mov == 2)) {
            colisoes += 2;
        }

        if (!posicao_valida(lab, novo_x, novo_y)) {
            colisoes += 5;
            break;
        }

        x = novo_x;
        y = novo_y;
        ult_mov = mov;

        if (x == lab->fim_x && y == lab->fim_y) break;
    }

    int dist = abs(x - lab->fim_x) + abs(y - lab->fim_y);
    ind->fitness = 1000 - dist - colisoes * 100;
}

void escrever_genoma_textual(Individuo* ind, FILE* saida) {
    for (int i = 0; i < ind->tamanho_genoma; i++) {
        switch (ind->genoma[i]) {
            case 0: fputc('C', saida); break; // cima
            case 1: fputc('B', saida); break; // baixo
            case 2: fputc('E', saida); break; // esquerda
            case 3: fputc('D', saida); break; // direita
        }
    }
}

void imprimir_caminho_individuo(Individuo* ind, Labirinto* lab) {
    char copia[lab->altura][lab->largura];
    for (int i = 0; i < lab->altura; i++)
        for (int j = 0; j < lab->largura; j++)
            copia[i][j] = lab->mapa[i][j];

    int x = lab->inicio_x;
    int y = lab->inicio_y;

    for (int i = 0; i < ind->tamanho_genoma; i++) {
        int mov = ind->genoma[i];
        int novo_x = x + (mov == 1) - (mov == 0);
        int novo_y = y + (mov == 3) - (mov == 2);

        if (!posicao_valida(lab, novo_x, novo_y)) break;

        x = novo_x;
        y = novo_y;

        if (copia[x][y] != 'E') copia[x][y] = '.';
        if (x == lab->fim_x && y == lab->fim_y) break;
    }

    for (int i = 0; i < lab->altura; i++) {
        for (int j = 0; j < lab->largura; j++) {
            printf("%c", copia[i][j]);
        }
        printf("\n");
    }
}

Individuo* copiar_individuo(Individuo* original) {
    Individuo* novo = criar_individuo(original->tamanho_genoma);
    novo->tamanho_genoma = original->tamanho_genoma;
    novo->fitness = original->fitness;
    memcpy(novo->genoma, original->genoma, original->tamanho_genoma * sizeof(int));
    // Copie outros campos se houver
    return novo;
}
