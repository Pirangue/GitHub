#include <stdio.h>
#include <stdlib.h>
#include "log.h"

Logger* criar_logger(const char* caminho_csv) {
    Logger* log = malloc(sizeof(Logger));
    log->arquivo = fopen(caminho_csv, "w");
    if (!log->arquivo) {
        perror("Erro ao criar arquivo de log");
        exit(1);
    }

    // Cabeçalho do CSV
    fprintf(log->arquivo, "Geracao,Fitness,Genoma\n");
    return log;
}

void registrar_geracao(Logger* log, int geracao, Individuo* melhor) {
    fprintf(log->arquivo, "%d,%d,", geracao, melhor->fitness);
    escrever_genoma_textual(melhor, log->arquivo);
    fprintf(log->arquivo, "\n");
    fflush(log->arquivo);
}

void fechar_logger(Logger* log) {
    if (log->arquivo) {
        fclose(log->arquivo);
    }
    free(log);
}
