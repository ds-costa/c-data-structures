/****************************************
*	TITLE: Projeto 03 - N rainhas
*	AUTHOR: David S. Costa		
*	DESCRIPTTION: Projeto 03 da disciplina ATP2, 
*	
*****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>

typedef struct node {
	char **mat;
	struct node *next;
} Node;

Node *addEnd(Node **head, int N, char board[][N], unsigned long *solutionsQuantity) {
	
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

Node* clear(Node *head, int N) {
	
    Node* tmp;
    int i;

	while(head != NULL) {
        tmp = head;
		head = head->next;
		
		for(i = 0; i < N; i++) {
    		free(tmp->mat[i]);
        }
		free(tmp->mat);

		free(tmp);
    }
	return head;
}

// Checamos apenas o lado esquerdo da matriz de [0, col - 1] pois não há rainhas nas colunas a direita de col (O backtracking vai da esquerda para a direita)
int canPlaceQueen(int N, char board[][N], int row, int col) {
    int i, j;
    //Linha da rainha
    for (j = 0; j < col; j++) {
        if(board[row][j] == '1') return 0;
    }
    //Diagonal superior (diagonal) da rainha
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == '1') return 0;
    }
    //Diagonal inferior (lower) da rainha
    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j] == '1') return 0;
    }
    return 1;
}

// Função recursiva que soluciona o problema
int nQueens(int N, char board[][N], int col, unsigned long *solutionsQuantity, Node **head) {

    int i;
    int isPossible = 0;

    // Se todas as rainhas foram posicionadas encerramos a execução de uma solução
    if (col == N) {
        // printSolution(N, board, solutionsQuantity, outStream);
        *head = addEnd(&(*head), N, board, solutionsQuantity);
        return 1;
    }

    // Dada a coluna iteramos sobre todas as suas linhas tentando inserir a rainha
    for (i = 0; i < N; i++) {
        //Verifica se a rainha pode ser colocada no tabuleiro
        if ( canPlaceQueen(N, board, i, col) ) {        
            // Coloca uma rainha no tabuleiro
            board[i][col] = '1';
            // Armazena o resultado da execução para a próxima coluna
            isPossible = nQueens(N, board, col + 1, solutionsQuantity, &(*head));
			// BACKTRACK
            board[i][col] = '0';
        }
    }
    //Retorna falso se não foi possível colocar a rainha em nenhuma linha da coluna atual (Esgotamento de soluções)
    return isPossible;
}

int main() {

    int i, j, N;
	unsigned long solutionsQuantity = 0;
    FILE *outStream = fopen("rainha.out", "w");
    Node *list = NULL;
    
    scanf("%d", &N);

    char board[N][N];

    // Inicializa o tabuleiro
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			board[i][j] = '0';
		}
	}
    
    nQueens(N, board, 0, &solutionsQuantity, &list);
    
    //Gravando em arquivo
    fprintf(outStream, "%ld\n\n", solutionsQuantity);
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

    list = clear(list, N); //Limpando lista
    fclose(outStream); //Fechando stream (FIM)

    return 0;
}

//com char em [16][16]: 3.78 gb
//com int em [16][16]: 16gb
//com short em [16][16]: 8gb