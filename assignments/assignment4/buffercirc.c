/****************************************
*       TITLE: Projeto 04 - Listas circulares
*       AUTHOR: David S. Costa
*       DESCRIPTTION: Projeto 04 da disciplina ATP2,
*****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define CIRCULAR_BUFFER_MAX_SIZE 40
#define CIRCULAR_BUFFER_WRITE_OPERATION 0
#define CIRCULAR_BUFFER_POP_OPERATION 1


typedef struct no {
    char pal[20];
    int urg;
    struct no *prox; 
} Elem;

//Cria um novo nó
Elem* newNode(char pal[20], int urg);
//Adiciona um nó a lista circular
void addNode(Elem** head, Elem** tail, Elem* elem);
//Libera a lista da memória
void deleteList(Elem** head, Elem**tail);
//Cria um buffer circular
void circularBufferInit(Elem** head, Elem** tail);
//Operação de push em buffer circular
void circularBufferRead(Elem** head, Elem** tail, int urg, char pal[20]);
//Operação de pop em buffer circular
void circularBufferWrite(Elem** head, Elem** tail, Elem** output);

int main()
{
    //Arquivos
    FILE* pacotes = fopen("pacotes.dat", "r"); // Entrada
    FILE* lidos = fopen("lidos.dat", "w"); // Saída

    //Lista circular com tamanho fixo (40 elementos) 
    Elem* head;
    Elem* tail;
    circularBufferInit(&head, &tail);
    // Elem* pr = head; //Debug

    //Variáveis auxiliares para leitura de arquivo de entrada
    int operation;
    int urg;
    char word[20];

    //Nó auxiliar, armazena o elemento "consumido" na operação de pop
    Elem* aux = (Elem*)malloc(sizeof(Elem));
    Elem* lastTailIndex;

    while(!feof(pacotes))
    {
        fscanf(pacotes, "%d %s %d", &operation, word, &urg);
        // printf("Debug: %d %s %d\n", operation, word, urg);

        if(strcmp(word, "NULL") == 0)
        {
            break;
        }

        if(operation == CIRCULAR_BUFFER_WRITE_OPERATION)
        {
            circularBufferRead(&head, &tail, urg, word);
        }
        else 
        {
            lastTailIndex = tail;
            
            circularBufferWrite(&head, &tail, &aux); // Valor consumido é armazenado em aux
        
            //Gravação em arquivo
            if(lastTailIndex != tail)
            {
                fprintf(lidos, "%s\n", aux->pal); 
            }
        }
        
    }

    fclose(pacotes);
    fclose(lidos);
    deleteList(&head, &tail);
    return 0;
}


//Cria um novo nó
Elem* newNode(char pal[20], int urg)
{
    Elem* new_node = (Elem *) malloc(sizeof(Elem));
    strcpy(new_node->pal, pal);
    new_node->urg = urg;
    new_node->prox = NULL;
    return new_node;
}

//Adiciona um nó a lista circular
void addNode(Elem** head, Elem** tail, Elem* elem)
{
    if(!(*head)) //Lista vazia
    {
        (*head) = (*tail) = elem;
        elem->prox = elem;        
    }
    else //1 ou mais elementos
    {
        (*tail)->prox = elem;
        elem->prox = (*head);
        (*tail) = elem;
    }
}

//Libera a lista da memória
void deleteList(Elem** head, Elem**tail)
{
    Elem* current = (*head);
    Elem* next;

    do
    {
        next = current->prox;
        free(current);
        current = next;
    } while(current->prox != (*tail));
    (*head) = (*tail) = NULL;
}

//Operação de push em buffer circular
void circularBufferRead(Elem** head, Elem** tail, int urg, char pal[20])
{
    Elem* next = (*head)->prox;

    if(next == *tail) {
        return;
    }
    (*head)->urg = urg;
    strcpy((*head)->pal, pal);
    (*head) = next;
}

//Operação de pop em buffer circular
void circularBufferWrite(Elem** head, Elem** tail, Elem** output)
{
    if(*head == *tail)
    {
        return;
    }
    Elem* next = (*tail)->prox;
    
    strcpy((*output)->pal, (*tail)->pal);
    (*output)->urg = (*tail)->urg;
    (*output)->prox = NULL;

    if(strcmp((*tail)->pal, "PRTY") == 0)
    {
        int count = (*tail)->urg;
     
        for(int i = 0; i < count; i++)
        {
            if(*tail == *head)
            {
                break;
            }
            (*tail) = (*tail)->prox;       
        }
    }
    else
    {
       (*tail) = next;
    }
}

void circularBufferInit(Elem** head, Elem** tail)
{
    int i;
    (*head) = (*tail) = NULL;
    for(i = 0; i < CIRCULAR_BUFFER_MAX_SIZE; i++)
    {
        addNode(head, tail, newNode("0", 0));
    }
    (*tail) = (*tail)->prox; //Head e Tail tem o mesmo índice
}
