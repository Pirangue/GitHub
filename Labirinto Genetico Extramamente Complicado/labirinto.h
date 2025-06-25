#ifndef LABIRINTO_H
#define LABIRINTO_H

#define MAX_LARGURA 100
#define MAX_ALTURA 100

typedef struct {
    char mapa[MAX_ALTURA][MAX_LARGURA];
    int largura;
    int altura;
    int inicio_x, inicio_y;
    int fim_x, fim_y;
} Labirinto;

/**
 * Carrega um labirinto a partir de um arquivo.
 * O arquivo deve conter o mapa do labirinto, com '0' para caminhos livres,
 * '1' para paredes, e 'S' para o início e 'F' para o fim.
 * @param caminho Caminho do arquivo do labirinto.
 * @return Um ponteiro para a estrutura Labirinto preenchida.
 *         Retorna NULL em caso de erro.
 */
Labirinto carregar_labirinto(const char* caminho);

/**
 * Inicializa um labirinto vazio com dimensões especificadas.
 * @param largura Largura do labirinto.
 * @param altura Altura do labirinto.
 * @return Um ponteiro para a estrutura Labirinto alocada dinamicamente.
 */
void imprimir_labirinto(Labirinto* lab);

/**
 * Verifica se uma posição (x, y) é válida dentro do labirinto.
 * Uma posição é válida se estiver dentro dos limites do labirinto
 * e não for uma parede.
 * @param lab Ponteiro para o labirinto.
 * @param x Coordenada x da posição a ser verificada.
 * @param y Coordenada y da posição a ser verificada.
 * @return 1 se a posição for válida, 0 caso contrário.
 */
int posicao_valida(Labirinto* lab, int x, int y);

/**
 * Libera a memória alocada para o labirinto.
 * Neste caso, não há alocação dinâmica, mas mantemos a função por organização.
 * @param lab Ponteiro para o labirinto a ser liberado.
 */
void liberar_labirinto(Labirinto* lab);

#endif
