#ifndef ALGORITIMO_GENETICO_H
#define ALGORITIMO_GENETICO_H

#include "configuracao.h"
#include "individuo.h"

/**
 * * Função que inicializa a população de indivíduos.
 * * A função percorre a população e inicializa cada indivíduo com um genoma aleatório.
 * * @param pop ponteiro para a população
 */
void inicializar_populacao(Populacao* pop);

/**
 * * Função que seleciona um indivíduo aleatório da população.
 * * A função percorre a população e escolhe um indivíduo aleatório.
 * * @param pop ponteiro para a população
 * @return TNo indivíduo selecionado
 */
TNo selecao_torneio(Populacao* pop);

/**
 * * Função que realiza o crossover entre dois indivíduos.
 * * A função percorre os genomas dos indivíduos e troca partes entre eles.
 * @param pai1 ponteiro para o primeiro pai
 * @param pai2 ponteiro para o segundo pai
 * @param filho ponteiro para o filho resultante do crossover
 */
void crossover(TNo* pai1, TNo* pai2, TNo* filho);

/**
 * * Função que realiza a mutação em um indivíduo.
 * * A função percorre o genoma do indivíduo e altera aleatoriamente alguns genes.
 * @param ind ponteiro para o indivíduo
 */
void mutacao(TNo* ind);

/**
 * * Função que gera uma nova geração de indivíduos.
 * * A função preserva o melhor indivíduo da geração anterior e gera novos indivíduos.
 * @param pop ponteiro para a população
 */
void nova_geracao(Populacao* pop);

#endif