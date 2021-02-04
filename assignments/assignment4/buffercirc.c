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
void addNode(Elem** write, Elem** read, Elem* elem);
//Libera a lista da memória
void deleteList(Elem** write, Elem**read);
//Cria um buffer circular
void circularBufferInit(Elem** write, Elem** read);
//Operação de push em buffer circular
void circularBufferRead(Elem** write, Elem** read, int urg, char pal[20]);
//Operação de pop em buffer circular
void circularBufferWrite(Elem** write, Elem** read, Elem** output);

int main()
{
    //Arquivos
    FILE* pacotes = fopen("pacotes.dat", "r"); // Entrada
    FILE* lidos = fopen("lidos.dat", "w"); // Saída

    //Lista circular com tamanho fixo (40 elementos) 
    Elem* write;
    Elem* read;
    circularBufferInit(&write, &read);
    // Elem* pr = write; //Debug

    //Variáveis auxiliares para leitura de arquivo de entrada
    int operation;
    int urg;
    char word[20];

    //Nó auxiliar, armazena o elemento "consumido" na operação de pop
    Elem* aux = (Elem*)malloc(sizeof(Elem));
    Elem* lastreadIndex;

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
            circularBufferRead(&write, &read, urg, word);
        }
        else 
        {
            lastreadIndex = read;
            
            circularBufferWrite(&write, &read, &aux); // Valor consumido é armazenado em aux
        
            //Gravação em arquivo
            if(lastreadIndex != read)
            {
                fprintf(lidos, "%s\n", aux->pal); 
            }
        }
        
    }

    fclose(pacotes);
    fclose(lidos);
    deleteList(&write, &read);
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
void addNode(Elem** write, Elem** read, Elem* elem)
{
    if(!(*write)) //Lista vazia
    {
        (*write) = (*read) = elem;
        elem->prox = elem;        
    }
    else //1 ou mais elementos
    {
        (*read)->prox = elem;
        elem->prox = (*write);
        (*read) = elem;
    }
}

//Libera a lista da memória
void deleteList(Elem** write, Elem**read)
{
    Elem* current = (*write);
    Elem* next;

    do
    {
        next = current->prox;
        free(current);
        current = next;
    } while(current->prox != (*read));
    (*write) = (*read) = NULL;
}

//Operação de push em buffer circular
void circularBufferRead(Elem** write, Elem** read, int urg, char pal[20])
{
    Elem* next = (*write)->prox;

    if(next == *read) {
        return;
    }
    (*write)->urg = urg;
    strcpy((*write)->pal, pal);
    (*write) = next;
}

//Operação de pop em buffer circular
void circularBufferWrite(Elem** write, Elem** read, Elem** output)
{
    if(*write == *read)
    {
        return;
    }
    Elem* next = (*read)->prox;
    
    strcpy((*output)->pal, (*read)->pal);
    (*output)->urg = (*read)->urg;
    (*output)->prox = NULL;

    if(strcmp((*read)->pal, "PRTY") == 0)
    {
        int count = (*read)->urg;
     
        for(int i = 0; i < count; i++)
        {
            if(*read == *write)
            {
                break;
            }
            (*read) = (*read)->prox;       
        }
    }
    else
    {
       (*read) = next;
    }
}

void circularBufferInit(Elem** write, Elem** read)
{
    int i;
    (*write) = (*read) = NULL;
    for(i = 0; i < CIRCULAR_BUFFER_MAX_SIZE; i++)
    {
        addNode(write, read, newNode("0", 0));
    }
    (*read) = (*read)->prox; //write e read tem o mesmo índice
}
