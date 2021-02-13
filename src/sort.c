#include <stdlib.h>

void bubbleSort(int arrayLenght, int *array) 
{
    int i, j, aux;
    for(i = 0; i < arrayLenght; i++) 
    {
        for(j = i + 1; j < arrayLenght; j++) 
        {
            if(array[i] > array[j]) 
            {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }
}

void selectionSort( int arrayLenght, int *array) 
{
    int i, j, min, aux;
    for(i = 0; i < arrayLenght; i++) 
    {
        min = i;
        for(j = i + 1; j < arrayLenght; j++) 
        {
            if( array[j] < array[min] ) 
            {
                min = j;
            }
        }
        if(array[i] != array[min]) 
        {
            aux = array[i];
            array[i] = array[min];
            array[min] = aux;
        }
    }
}

void insertionSort(int arrayLenght, int *array) 
{
    int i, j, aux;
    for(i = 1; i < arrayLenght; i++) 
    {
        aux = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > aux) 
        {
            array[j + 1] = array[j];
            j -= 1;
        }
        array[j + 1] = aux;
    }
}

void quickSort(int low, int high, int *array) 
{
    int i, j, pivot, aux;
    
    i = low;
    j = high - 1;
    pivot = array[(low + high) / 2]; //middle

    while(i <= j) 
    {
        
        while(array[i] < pivot && i < high)
        {
            i++;
        }
        
        while(array[j] > pivot && j > low)
        {
            j--;
        }

        if(i <= j) 
        {
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            i++;
            j--;
        }
    }

    if(j > low)
    {
        quickSort(low, j + 1, array);
    } 
    if(i < high)
    {
        quickSort(i, high, array);
    }
}

// void makeHeap(int *array, int begin, int end) {
//     int aux = array[begin]; 
//     int j = begin*2+1; //left heap child

//     //enquanto j for menorigual ao final do vetor
//     while(j <= end) {
//         if(j < end) {
//             if(array[j] < array[j+1]) {
//                 j++;
//             }
//         }
//         if(aux < array[j]) {
//             array[begin] = array[j];
//             begin = j;
//             j = 2*begin+1;
//         }
//         else {
//             j = end + 1;
//         }
//         array[begin] = aux;
//     }
// }

// void heapSort(int *array, int arrayLenght) {
//     int i, aux;

//     for(i = (arrayLenght - 1)/2; i >= 0 ; i--) { 
//         makeHeap(array, i, arrayLenght - 1);
//     }

//     for(i = (arrayLenght - 1); i >= 1; i--) {
//         aux = array[0];
//         array[0] = array[i];
//         array[i] = aux;
//         makeHeap(array, 0, i - 1);
//     }
// }

// //merge sort

// void merge(int *array, int begin, int middle, int end) {
    
//     int i = begin, j = middle + 1, aux = 0, len = end - begin + 1;
//     int *auxArray = calloc(len, sizeof(int));

//     while( i <= middle && j <= end ) {
        
//         if( array[i] < array[j] ) {
//             auxArray[aux] = array[i];
//             i++;
//         }
//         else {
//             auxArray[aux] = array[j];
//             j++;
//         }
//         aux++;
//     }

//     while( i <= middle ) {
//         auxArray[aux] = array[i];
//         aux++;
//         i++;
//     }

//     while( j <= end ) {
//         auxArray[aux] = array[j];
//         aux++;
//         j++;
//     }

//     for(aux = begin; aux <= end; aux++) {
//         array[aux] = auxArray[aux - begin];
//     }

//     free(auxArray);
// }

// void mergeSort(int *array, int begin, int end) {
//     if(begin < end) {
//         int middle = (begin + end)/2;
//         mergeSort(array, begin, middle);
//         mergeSort(array, middle + 1, end);
//         merge(array, begin, middle, end);
//     }
// }