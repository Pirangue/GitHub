#include "mapa.h"
#include <stdio.h>

char labirinto[ALTURA][LARGURA] = {
    "################",
    "#S       #     #",
    "#  ### #   ##  #",
    "#      #  ###  #",
    "# ## #### #    #",
    "#      #   #####",
    "# ### ## ###   #",
    "# #          # #",
    "# ### ###### # #",
    "#     #       E#",
    "################"
};

int inicio_x, inicio_y, fim_x, fim_y;

void imprimir_labirinto() {
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            printf("%c", labirinto[i][j]);
        }
        printf("\n");
    }
}

void encontrar_posicoes() {
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            if (labirinto[i][j] == 'S') {
                inicio_x = i;
                inicio_y = j;
            }
            if (labirinto[i][j] == 'E') {
                fim_x = i;
                fim_y = j;
            }
        }
    }
}