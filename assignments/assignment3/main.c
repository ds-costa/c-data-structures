/****************************************
*	TITLE: Projeto 03 - N rainhas
*	AUTHOR: David S. Costa		
*	DESCRIPTTION: Projeto 03 da disciplina ATP2, 
*	
*****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Tipo de dado "nó" para listas encadeadas
typedef struct node {
	char **mat;
	struct node *next;
} Node;

//Adiciona um nó (nodo) no fim da lista encadeada
Node *addNode(Node **head, int N, char board[][N], unsigned long *solutionsQuantity);
// Limpa uma lista encadeada
Node* clearList(Node *head, int N);

// Função recursiva que soluciona o problema das n-rainhas
int nQueens(int N, char board[][N], int col, unsigned long *solutionsQuantity, Node **head);
// Função auxiliar que verifica se é possivel inserir a rainha no tabuleiro
int canPlaceQueen(int N, char board[][N], int row, int col);

int main() {

    int i, j, N;
	unsigned long solutionsQuantity = 0;
    FILE *outStream = fopen("rainha.out", "w");
    Node *list = NULL;
    
    scanf("%d", &N); //Entrada lida por teclado (stdin)

    char board[N][N]; 

    // Inicializa o tabuleiro
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			board[i][j] = '0';
		}
	}
    
    //Resolve o problema e grava as soluções em list
    nQueens(N, board, 0, &solutionsQuantity, &list);
    
    //Gravando em arquivo
    fprintf(outStream, "%ld\n\n", solutionsQuantity);
    //Aponta para o primeiro nó da lista
    Node *current = list;

    while(current != NULL) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                fprintf(outStream, "%c", current->mat[i][j]);
            } fprintf(outStream, "\n");
        }
        current = current->next;               
        fprintf(outStream, "\n\n"); 
    }

    //Limpando lista
    list = clearList(list, N);
    //Fechando stream de arquivo
    fclose(outStream); 

    return 0;
}

Node *addNode(Node **head, int N, char board[][N], unsigned long *solutionsQuantity) {
	
    int i, j;
	Node *current = *head;
	Node *new = malloc(sizeof(Node *));

    *solutionsQuantity += 1; //Incremento no contador de soluções
 
    //Alocando espaço para matriz
    char **a = malloc(N * sizeof(*a));
    for (i = 0; i < N; i++) {
        a[i] = malloc(N * sizeof *a[i]);
    }
    new->mat = a;

    //Copiando conteúdo de board para matriz
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			new->mat[i][j] = board[i][j];
		}
	}

    //Tratamento para primeiro nó da lista
	if(*head == NULL) {
		new->next = NULL;
		return new;
	}

    //Inserção no final da lista
	while(current->next != NULL) {
		current = current->next;
	}
	current->next = new;
	return *head;
}


Node* clearList(Node *head, int N) {
    Node* tmp;
    int i;

	while(head != NULL) {
        tmp = head;
		head = head->next;

        //Desaloca matriz	
        for(i = 0; i < N; i++) {
    		free(tmp->mat[i]);
        } free(tmp->mat);
        
        //Desaloca ponteiro de lista
		free(tmp);
    }
	return head;
}

int canPlaceQueen(int N, char board[][N], int row, int col) {
    int i, j;
    //Linha da rainha
    for (j = 0; j < col; j++) {
        if(board[row][j] == '1') return 0;
    }
    //Diagonal superior (upper) da rainha
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == '1') return 0;
    }
    //Diagonal inferior (lower) da rainha
    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j] == '1') return 0;
    }
    return 1;
}

int nQueens(int N, char board[][N], int col, unsigned long *solutionsQuantity, Node **head) {
    int i;
    // Se todas as rainhas foram posicionadas encerramos a execução de uma solução
    if (col == N) {
        *head = addNode(&(*head), N, board, solutionsQuantity);
        return 1;
    }
    // Dada a coluna iteramos sobre todas as suas linhas tentando inserir a rainha
    for (i = 0; i < N; i++) {
        //Verifica se a rainha pode ser colocada no tabuleiro
        if ( canPlaceQueen(N, board, i, col) ) {        
            // Coloca uma rainha no tabuleiro
            board[i][col] = '1';
            // Verifica recursivamente se a rainha posicionada leva a uma solução
            nQueens(N, board, col + 1, solutionsQuantity, &(*head));
			// BACKTRACK, a rainha é removida do tabuleiro caso sua posição não leve a uma solução
            board[i][col] = '0';
        }
    }
    //Retorna falso se não foi possível colocar a rainha em nenhuma linha da coluna atual (Esgotamento de soluções)
    return 0;
}