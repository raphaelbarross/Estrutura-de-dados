#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 10

typedef struct {
    int r, f, quant;
    int vet[TAM];
}filavet;

void enfileira(int valor, filavet *p){
    if (p -> quant == TAM){
        printf("\nFila Cheia!");
        exit(0);
    }
    if(p -> r == TAM-1){
        p-> r = 0;
    }
    else{
        p -> r++;
    }
    
    p->vet[p -> r]=valor;
    p-> quant++;
}

int desenfileira(filavet *p){
    int elem;
    if(p -> quant == 0){
        printf("\nFila vazia!");
        exit(1);
    }

    elem = p -> vet[p -> f];

    if(p -> f == TAM - 1){
        p -> f = 0;
    }
    else{
        p -> f++;
    }

    p -> quant--;
    return elem;
}  

int main() {
    filavet fila;
    int valor;
    fila.r = -1;
    fila.f = 0;
    fila.quant = 0;
    for(int i = 0; i < TAM ; i++){
        printf("\nDigite o valor a ser enfileirado: ");
        scanf("%d", &valor);
        enfileira(valor, &fila);
    }
    for(int i = 0; i < TAM; i++){
        printf("\n%d", desenfileira(&fila));
    }
}