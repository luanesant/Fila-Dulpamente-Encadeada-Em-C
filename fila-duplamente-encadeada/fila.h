#ifndef FILA_H
#define FILA_H

typedef struct No{
    int idade;
    struct No* anterior;
    struct No* proximo;
}No;

typedef struct{
    No* prim;
    No* ult;
}Fila;


Fila* criar_fila();

void inserir_final_da_fila(Fila* fila, int idade);
void imprimir_fila(Fila* fila);
void liberar_fila(Fila* fila );

int fila_vazia(Fila* fila);
int elementos_fila(Fila* fila);
int retirar_primeiro_no_da_fila(Fila* fila);

#endif