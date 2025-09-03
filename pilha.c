#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct{
	int vet[TAM];
	int topo;
}pilhavet;

void empilhar(int valor, pilhavet *p){
	if(p -> topo == TAM-1){
		printf("\nPilha cheia");
		exit(0);
	}
	p -> topo++;
	p -> vet[p -> topo] = valor;
}

int desempilhar(pilhavet *p){
	if(p -> topo < 0){
		printf("\nPilha vazia");
		exit(1);
	}
	int aux = p -> vet[p -> topo];
	p -> topo--;
	return aux;
}

int main(){
	pilhavet pilha;
	int num;
	pilha.topo = -1;
	
	for(int i = 0; i < TAM; i++){
		printf("Digite um número para empilhar: ");
		scanf("%d", &num);
		empilhar(num, &pilha);
	}
	
	for(int i = 0; i < TAM; i++){
		printf("%d\n", desempilhar(&pilha));
	}
}