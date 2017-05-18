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

int menu(node *LIST);
void inserir(node *LIST);
void remover(node *LIST);
void buscar(node *LIST);
void listar(node *LIST);

int main() {
	node *LIST = (node *) malloc(sizeof(node));
	
	while(menu(LIST)!=1);

	return 0;
}


int menu(node *LIST) {
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
		case 1: inserir(LIST);
			break;

		case 2: remover(LIST);
			break;

		case 3: buscar(LIST);
			break;

		case 4: listar(LIST);
			break;

		case 5: return 1;
			break;

		default: printf("Opcao Invalida\n");
	}

	return 0;
}

void inserir(node *LIST) {
	node *new = (node *) malloc(sizeof(node));
	
	printf("Entre com a nova chave: ");
	scanf("%d", &new->key);
	new->next = LIST->next;

	node *aux = (node *) malloc(sizeof(node));
	aux =  LIST->next;

	while(aux->next != LIST->next) {
		aux = aux->next;
	}

	aux->next = new;
}

void remover(node *LIST) {
	int key;

	printf("Entre com a chave: ");
	scanf("%d", &key);

	if(LIST->next != NULL) {
		node *aux = (node *) malloc(sizeof(node));
		aux = LIST->next;

		while(aux!=NULL) {
			if(aux->next->key==key) {
				node *aux2 = (node *) malloc(sizeof(node));
				aux2 = aux->next;
				aux->next = aux->next->next;
				free(aux2);
				return; //aborta a funcao
			}
		}

		printf("A chave nao existe na lista.\n");

	} else {
		printf("A lista esta vazia\n");
	}
}

void buscar(node *LIST) {
	int key;

	if(LIST->next != NULL) {
		printf("Entre com a chave: ");
		scanf("%d", &key);
		node *aux = (node *) malloc(sizeof(node));
		aux = LIST->next;
		int cont = 0;

		while(aux->next!=LIST->next){
			cont++;
			if(aux->key==key) {
				printf("A chave procurada esta na posicao %d da fila\n", cont);
				return; //aborta a função
			}
			aux = aux->next;
		}

		printf("A chave não existe na fila");
	} else {
		printf("A lista esta vazia");
	}
}

void listar(node *LIST) {
	node *aux = (node *) malloc(sizeof(node));
	aux = LIST->next;

	while(aux->next!=LIST->next){
		printf("[%p] (%d) -> (%p) \n", aux, aux->key, aux->next);
		aux = aux->next;
	}
}