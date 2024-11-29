#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * Função responsável por alocar e criar um ponteiro de FILA;
 */
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

/**
 * Função responsável por inserir um novo elemento no final da fila;
 */
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

/**
 * Função responsável por imprimir os elementos da FILA;
 */
void imprimir_fila(Fila* fila){

    No* no = fila->prim;
    for (; no != NULL; no = no->proximo){
        printf("%d", no->idade);
    }
    printf("\n");

}

/**
 * Função responsável por verificar se a FILA está vazia;
 */
int fila_vazia(Fila* fila){
    return (fila->prim == NULL);
}

/**
 * Função responsável por verificar quantos elementos estão contidos na FILA;
 */
int elementos_fila(Fila* fila){
    int qtd = 0;
    No* no = fila->prim;
    for (; no != NULL; no = no->proximo){
        qtd++;
    }

    return qtd;
}

/**
 * Função responsável por desalocar memória da FILA;
 */
void liberar_fila(Fila* fila ){
    No* no = fila->prim;
    while (no != NULL){
        No* no_liberado = no->proximo;
        free(no_liberado);
        no = no_liberado;
    }

    free(no);    
}

/**
 * Função responsável por remover um a uma os elementos da FILA;
 */
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