#ifndef CONFIG_H
#define CONFIG_H

typedef struct {
    int tamanho_populacao;
    float taxa_mutacao;
    int max_geracoes;
    char versao_geracao[20];   // "aleatoria" ou "inteligente"
    char arquivo_mapa[100];
    char arquivo_saida_log[100];
} Config;

/**
 * Carrega as configurações a partir de um arquivo.
 * @param caminho Caminho do arquivo de configuração.
 * @return Um ponteiro para a estrutura Config preenchida.
 *         Retorna NULL em caso de erro.
 */
Config* carregar_config(const char* caminho);

/**
 * Libera a memória alocada para a estrutura Config.
 * @param cfg Ponteiro para a estrutura Config a ser liberada.
 */
void liberar_config(Config* cfg);

#endif
