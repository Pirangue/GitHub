#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include "individuo.h"

typedef struct {
    FILE* arquivo;
} Logger;

Logger* criar_logger(const char* caminho_csv);
void registrar_geracao(Logger* log, int geracao, Individuo* melhor);
void fechar_logger(Logger* log);

#endif
