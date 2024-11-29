#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

Fila* criar_fila(){
    Fila* fila = malloc(sizeof(Fila));
    if(fila == NULL){
        printf("Erro ao alocar memoria");
        exit(1);
    }

    fila->prim = NULL;
    fila->ult = NULL;

    return fila;
}

void inserir_final_da_fila(Fila* fila, int idade){
    No* novo = malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro ao alocar memoria");
        exit(1);
    }

    novo->idade = idade;
    novo->anterior = fila->ult;
    novo->proximo = NULL;
    
    if (fila->ult == NULL){
         fila->prim = novo;
    }else{ 
        fila->ult->proximo = novo; // original
    }
    
    fila->ult = novo;
    
}

void imprimir_fila(Fila* fila){

    No* no = fila->prim;
    for (; no != NULL; no = no->proximo){
        printf("%d", no->idade);
    }
    printf("\n");
}

int fila_vazia(Fila* fila){
    return (fila->prim == NULL);
}

int elementos_fila(Fila* fila){
    int qtd = 0;
    No* no = fila->prim;
    for (; no != NULL; no = no->proximo){
        qtd++;
    }

    return qtd;
}

void liberar_fila(Fila* fila ){
    No* no = fila->prim;
    while (no != NULL){
        No* no_liberado = no->proximo;
        free(no_liberado);
        no = no_liberado;
    }

    free(no);    
}

int retirar_primeiro_no_da_fila(Fila* fila) {
    if (fila == NULL || fila->prim == NULL) {
        return -1; 
    }

    No* no_para_retirar = fila->prim;
    int idade_liberada = no_para_retirar->idade;

    fila->prim = no_para_retirar->proximo;

    if (fila->prim != NULL) {
        fila->prim->anterior = NULL;
    } else {
        fila->ult = NULL;
    }

    free(no_para_retirar);
    return idade_liberada;
}