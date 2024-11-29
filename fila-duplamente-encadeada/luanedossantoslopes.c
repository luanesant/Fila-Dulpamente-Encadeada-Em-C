#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h"

/**
 * Função responsável por ordenar crescentemente os dados da FILA;
 */
void ordenar_fila(Fila* fila){
    if (fila_vazia(fila)){
       printf("Fila Vazia!\n");
       return;
    }
    No* ultimo = NULL;
    for(int i = 0; i < elementos_fila(fila); i++){
        No* atual = fila->prim;
        No* anterior = NULL;
        while (atual->proximo != ultimo) {
            if (atual->idade < atual->proximo->idade) {
                No* proximo_no = atual->proximo;

                atual->proximo = proximo_no->proximo;
                atual->anterior = proximo_no;

                proximo_no->proximo = atual;
                proximo_no->anterior = anterior;

                if (atual->proximo != NULL) {
                    atual->proximo->anterior = atual;
                }

                if (anterior != NULL) {
                    anterior->proximo = proximo_no;
                } else {
                    fila->prim = proximo_no; 
                }

                if (atual->proximo == NULL) {
                    fila->ult = atual;
                }

                anterior = proximo_no;

            } else {
                anterior = atual;
                atual = atual->proximo;
            }
        }
        ultimo = atual;
    }
    // fila->ult = atual;
}

int main(){
    Fila* fila = criar_fila();

    FILE* arquivo = fopen("clientes.txt", "r");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo clientes.txt\n");
        return 1;
    }
    printf("==========================\n");
    printf("|  LENDO IDADES DA FILA  |\n");
    printf("==========================\n");

    int idade;
    while (fscanf(arquivo, "%d", &idade) == 1) {
        inserir_final_da_fila(fila, idade);
    }

    fclose(arquivo);
    printf("=========================\n");
    printf("|  ORDENANDO A FILA...  |\n");
    printf("=========================\n");

    ordenar_fila(fila);
    printf("===================================\n");
    printf("|   FILA DE ATENDIMENTO ORDENADA  |\n");
    printf("===================================\n");

    while (!fila_vazia(fila)) {
        int idade = retirar_primeiro_no_da_fila(fila);
        printf("| Cliente com idade: %3d ATENDIDO |\n", idade);
    }   
    printf("===================================\n");

    liberar_fila(fila);

return 0;
}