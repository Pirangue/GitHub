#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include "../Povo/individuo.h"

typedef struct {
    FILE* arquivo;
} Logger;

/**
 * Cria um logger para registrar informações de gerações em um arquivo CSV.
 * @param caminho_csv Caminho do arquivo CSV onde os dados serão registrados.
 * @return Um ponteiro para a estrutura Logger alocada dinamicamente.
 *         Retorna NULL em caso de erro de alocação de memória.
 */
Logger* criar_logger(const char* caminho_csv);

/**
 * Registra uma geração no arquivo de log.
 * @param log Ponteiro para o logger onde os dados serão registrados.
 * @param geracao Número da geração a ser registrada.
 * @param melhor Ponteiro para o indivíduo com o melhor fitness da geração.
 */
void registrar_geracao(Logger* log, int geracao, Individuo* melhor);

/**
 * Fecha o logger e libera a memória alocada.
 * @param log Ponteiro para o logger a ser fechado.
 */
void fechar_logger(Logger* log);

#endif
