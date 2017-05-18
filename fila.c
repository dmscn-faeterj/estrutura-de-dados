/*
 * fila simplesmente encadeada :
 * inserir / remover / buscar / mostrar 
 * print example :
 * [endereço] (chave) -> (prox)
 * 	
 * pilha duplamente encadeada :
 * inserir / remover / buscar / mostrar
 * print example : 
 * [endereço] (ant) <- (chave) -> (prox)
 *
 * desafio fila circular sequencial :
 * inserir / remover
 *
 * complexidade media : 
 * calcular a complexidade media de uma 
 * busca sequencial em uma lista onde a 
 * probabilidade do elemento ser encontrado 
 * em cada posição é a mesma. Considere q a
 * probabilidade de encontrar o elemento e o
 * caso contrario 1-q.
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *next;
};

typedef struct node node;

int menu(node *FILA);
void inserir(node *FILA);
void remover(node *FILA);
void buscar(node *FILA);
void listar(node *FILA);

int main() {
	node *FILA = (node *) malloc(sizeof(node));
	
	while(menu(FILA)!=1);

	return 0;
}


int menu(node *FILA) {
	int op;

	printf("\n================== MENU ==================\n");
	printf("1- INSERIR\n");
	printf("2- REMOVER\n");
	printf("3- BUSCAR\n");
	printf("4- LISTAR\n");
	printf("5- SAIR\n");
	printf("==========================================\n\n");
	printf("Entre com a opção: ");
	scanf("%d", &op);

	printf("\n");

	switch(op) {
		case 1: inserir(FILA);
			break;

		case 2: remover(FILA);
			break;

		case 3: buscar(FILA);
			break;

		case 4: listar(FILA);
			break;

		case 5: return 1;
			break;

		default: printf("Opcao Invalida\n");
	}

	return 0;
}

void inserir(node *FILA) {
	node *new = (node *) malloc(sizeof(node));
	
	printf("Entre com a nova chave: ");
	scanf("%d", &new->key);

	node *aux = (node *) malloc(sizeof(node));
	aux =  FILA;

	while(aux->next != NULL) {
		aux = aux->next;
	}

	aux->next = new;
}

void remover(node *FILA) {
	if(FILA->next != NULL) {
		node *aux = (node *) malloc(sizeof(node));
		aux = FILA->next;
		FILA->next = aux->next;
		free(aux);
	} else {
		printf("A fila esta vazia\n");
	}
}

void buscar(node *FILA) {
	int key;

	if(FILA->next != NULL) {
		printf("Entre com a chave: ");
		scanf("%d", &key);
		node *aux = (node *) malloc(sizeof(node));
		aux = FILA->next;
		int cont = 0;

		while(aux->next!=NULL){
			cont++;
			if(aux->key==key) {
				printf("A chave procurada esta na posicao %d da fila\n", cont);
				return; //aborta a função
			}
			aux = aux->next;
		}

		printf("A chave não existe na fila");
	} else {
		printf("A fila esta vazia");
	}
}

void listar(node *FILA) {
	node *aux = (node *) malloc(sizeof(node));
	aux = FILA->next;

	while(aux != NULL ){
		printf("[%p] (%d) -> (%p) \n", aux, aux->key, aux->next);
		aux = aux->next;
	}
}