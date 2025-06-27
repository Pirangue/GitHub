#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "Config/config.h"
#include "Labirinto/labirinto.h"
#include "Povo/individuo.h"
#include "Povo/populacao.h"
#include "Log/log.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Uso: %s <mapa.ini> <config.ini>\n", argv[0]);
        return 1;
    }

    srand(time(NULL));

    // Ler arquivo de configuração
    Config* config = carregar_config(argv[2]);

    // Carregar o labirinto
    Labirinto lab = carregar_labirinto(argv[1]);
    printf("Mapa carregado:\n");
    imprimir_labirinto(&lab);
    printf("\n");

    // Criar arquivo de log
    Logger* log = criar_logger(config->arquivo_saida_log);

    // Inicializar população
    Populacao* pop = criar_populacao(config->tamanho_populacao, &lab, config->versao_geracao);

    // Executar gerações
    for (int geracao = 1; geracao <= config->max_geracoes; geracao++) {
        Individuo* melhor = obter_melhor_individuo(pop);

        printf("\nGeracao %d:\n", geracao);
        printf("Melhor fitness: %d\n", melhor->fitness);
        imprimir_caminho_individuo(melhor, &lab);

        registrar_geracao(log, geracao, melhor);

        if (melhor->fitness >= 1000) {
            printf("\nSolucao encontrada!\n");
            break;
        }

        nova_geracao(pop, &lab, config->versao_geracao);
    }

    // Finalizar
    liberar_populacao(pop);
    fechar_logger(log);
    liberar_config(config);

    return 0;
}
