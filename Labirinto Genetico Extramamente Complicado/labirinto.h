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

Labirinto carregar_labirinto(const char* caminho);
void imprimir_labirinto(Labirinto* lab);
int posicao_valida(Labirinto* lab, int x, int y);
void liberar_labirinto(Labirinto* lab);

#endif
