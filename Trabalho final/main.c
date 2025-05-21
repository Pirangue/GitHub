#include "Algoritimo Genetico.h"
#include "configuracao.h"
#include "individuo.h"
#include "mapa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


int main() {
    srand(time(NULL));
    imprimir_labirinto();
    encontrar_posicoes();

    Populacao populacao = {NULL, 0};
    inicializar_populacao(&populacao);

    int geracao = 0;
    TNo* melhor;
    do {
        printf("\nGeracao %d:\n\n", geracao + 1);

        // Encontrar o melhor indivíduo
        TNo* atual = populacao.cabeca;
        melhor = atual;
        while (atual != NULL) {
            if (atual->fitness > melhor->fitness) {
                melhor = atual;
            }
            atual = atual->prox;
        }

        printf("Melhor fitness: %d\n", melhor->fitness);
        simular_caminho(melhor);

        if (melhor->fitness >= 1000) {
            printf("Solucao encontrada!\n");
            break;
        }

        nova_geracao(&populacao);
        geracao++;
    } while (melhor->fitness < 1000);

    liberar_lista(&populacao);
    return 0;
}