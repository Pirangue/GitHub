#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#include "../Labirinto/labirinto.h"

typedef struct Individuo {
    int* genoma;
    int tamanho_genoma;
    int fitness;
} Individuo;

/**
 * Cria um novo indivíduo com um genoma de tamanho especificado.
 * @param tamanho Tamanho do genoma.
 * @return Um ponteiro para a estrutura Individuo alocada dinamicamente.
 *         Retorna NULL em caso de erro de alocação de memória.
 */
Individuo* criar_individuo(int tamanho);

/**
 * Libera a memória alocada para um indivíduo.
 * @param ind Ponteiro para o indivíduo a ser liberado.
 */
void liberar_individuo(Individuo* ind);

/**
 * Inicializa o genoma de um indivíduo com movimentos aleatórios.
 * Cada movimento é representado por um número de 0 a 3:
 * 0 = cima, 1 = baixo, 2 = esquerda, 3 = direita.
 * @param ind Ponteiro para o indivíduo cujo genoma será inicializado.
 */
void inicializar_genoma_aleatorio(Individuo* ind);

/**
 * Inicializa o genoma de um indivíduo com movimentos inteligentes,
 * evitando colisões e tentando se mover dentro dos limites do labirinto.
 * @param ind Ponteiro para o indivíduo cujo genoma será inicializado.
 * @param lab Ponteiro para o labirinto onde os movimentos serão realizados.
 */
void inicializar_genoma_inteligente(Individuo* ind, Labirinto* lab);

/**
 * Calcula o fitness de um indivíduo com base no seu genoma e no labirinto.
 * O fitness é calculado considerando a distância até o objetivo e penalidades por colisões.
 * @param ind Ponteiro para o indivíduo cujo fitness será calculado.
 * @param lab Ponteiro para o labirinto onde os movimentos serão realizados.
 */
void calcular_fitness(Individuo* ind, Labirinto* lab);

/**
 * Escreve o genoma de um indivíduo em um arquivo de saída.
 * Cada movimento é representado por um caractere: 
 * 'C' (cima), 'B' (baixo), 'E' (esquerda), 'D' (direita).
 * @param ind Ponteiro para o indivíduo cujo genoma será escrito.
 * @param saida Ponteiro para o arquivo de saída onde o genoma será escrito.
 */
void escrever_genoma_textual(Individuo* ind, FILE* saida);

/**
 * Imprime o caminho percorrido por um indivíduo no labirinto,
 * substituindo os espaços percorridos por '.' e mantendo as paredes intactas.
 * @param ind Ponteiro para o indivíduo cujo caminho será impresso.
 * @param lab Ponteiro para o labirinto onde o caminho será impresso.
 */
void imprimir_caminho_individuo(Individuo* ind, Labirinto* lab);

/**
 * Copia um indivíduo, alocando memória para um novo indivíduo e copiando os dados.
 * @param original Ponteiro para o indivíduo a ser copiado.
 * @return Um ponteiro para o novo indivíduo copiado.
 *         Retorna NULL em caso de erro de alocação de memória.
 */
Individuo* copiar_individuo(Individuo* original);

#endif
