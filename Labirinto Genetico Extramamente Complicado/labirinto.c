#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labirinto.h"

Labirinto carregar_labirinto(const char* caminho) {
    Labirinto lab;
    FILE* arq = fopen(caminho, "r");
    if (!arq) {
        perror("Erro ao abrir o arquivo do labirinto");
        exit(1);
    }

    char linha[MAX_LARGURA];
    lab.altura = 0;
    while (fgets(linha, sizeof(linha), arq) && lab.altura < MAX_ALTURA) {
        int len = strlen(linha);
        if (linha[len - 1] == '\n') linha[len - 1] = '\0'; // remove '\n'
        strcpy(lab.mapa[lab.altura], linha);
        lab.altura++;
    }

    fclose(arq);
    lab.largura = strlen(lab.mapa[0]);

    // Procurar posições de início e fim
    for (int i = 0; i < lab.altura; i++) {
        for (int j = 0; j < lab.largura; j++) {
            if (lab.mapa[i][j] == 'S') {
                lab.inicio_x = i;
                lab.inicio_y = j;
            }
            if (lab.mapa[i][j] == 'E') {
                lab.fim_x = i;
                lab.fim_y = j;
            }
        }
    }

    return lab;
}

void imprimir_labirinto(Labirinto* lab) {
    for (int i = 0; i < lab->altura; i++) {
        printf("%s\n", lab->mapa[i]);
    }
}

int posicao_valida(Labirinto* lab, int x, int y) {
    return x >= 0 && x < lab->altura &&
           y >= 0 && y < lab->largura &&
           lab->mapa[x][y] != '#';
}

void liberar_labirinto(Labirinto* lab) {
    // Nada para liberar aqui, mas mantemos a função por organização
}
