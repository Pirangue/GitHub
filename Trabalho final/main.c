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

    Populacao populacao;
    inicializar_populacao(&populacao);

    int geracao = 0;
    TNo melhor;
    do {
        printf("\nGeracao %d:\n\n", geracao + 1);

        // Encontrar o melhor indivíduo
        melhor = populacao.individuos[0];
        for (int i = 1; i < POPULACAO; i++) {
            if (populacao.individuos[i].fitness > melhor.fitness) {
                melhor = populacao.individuos[i];
            }
        }

        printf("Melhor fitness: %d\n", melhor.fitness);
        simular_caminho(&melhor);

        if (melhor.fitness >= 1000) {
            printf("Solucao encontrada!\n");
            break;
        }

        nova_geracao(&populacao);
        geracao++;
    } while (melhor.fitness < 1000);

    return 0;
}