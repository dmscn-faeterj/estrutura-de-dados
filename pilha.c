/* pilha duplamente encadeada :
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
	struct node *prev;
	struct node *next;
};

typedef struct node node;

int menu(node *PILHA);
void inserir(node *PILHA);
void remover(node *PILHA);
void buscar(node *PILHA);
void listar(node *PILHA);

int main() {
	node *PILHA = (node *) malloc(sizeof(node));
	PILHA->prev = NULL;
	PILHA->next = NULL;
	int sair;

	do {
		sair = menu(PILHA);
	} while (sair==0);
}

int menu(node *PILHA) {
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
		case 1: inserir(PILHA);
			break;

		case 2: remover(PILHA);
			break;

		case 3: buscar(PILHA);
			break;

		case 4: listar(PILHA);
			break;

		case 5: return 1;
			break;

		default: printf("Opcao Invalida\n");
	}

	return 0;
}

void inserir(node *PILHA) {
	node *new = (node *) malloc(sizeof(node));

	printf("Entre com a nova chave: ");
	scanf("%d", &new->key);
	new->next = NULL;
	
	node *aux = (node *) malloc(sizeof(node));
	aux = PILHA;

	while(aux->next!=NULL) {
		aux = aux->next;
	}

	aux->next = new;
	new->prev = aux;
}

void remover(node *PILHA) {
	if(PILHA->next!=NULL) {
		node *aux = (node *) malloc(sizeof(node));
		aux = PILHA;
		while(aux->next!=NULL) {
			aux = aux->next;
		}
		aux->prev->next = NULL;
		free(aux);
	} else {
		printf("A pilha esta vazia.\n");
	}
}

void buscar(node *PILHA) {
	if(PILHA->next!=NULL) {
		node *aux = (node *) malloc(sizeof(node));
		aux = PILHA->next;
		int key;
		int i = 1;

		printf("Entre com a chave: ");
		scanf("%d", &key);
		
		while(aux!=NULL){
			if(aux->key==key) {
				printf("A chave procurada está na posição %d da pilha.\n", i);
				return; //aborta a funcao
			}
			aux = aux->next;
			i++;
		}

		printf("A chave procurada nao existe nessa pilha.\n");
	} else {
		printf("A pilha esta vazia.\n");
	}
}

void listar(node *PILHA) {
	if(PILHA->next!=NULL) {
		node *aux = (node *) malloc(sizeof(node));
		aux = PILHA->next;

		while(aux!=NULL) {
			printf("[%p] (%p) <- (%d) -> (%p) \n", aux, aux->prev, aux->key, aux->next);
			aux = aux->next;
		}
	} else {
		printf("A pilha esta vazia.\n");
	}
}