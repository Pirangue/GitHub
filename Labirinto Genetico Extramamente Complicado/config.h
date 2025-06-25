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

Config* carregar_config(const char* caminho);
void liberar_config(Config* cfg);

#endif
