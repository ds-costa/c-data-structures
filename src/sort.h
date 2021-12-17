#ifndef SORT_H
#define SORT_H

#include <stdlib.h>

/**
 * @brief Selection Sort Algorithm implementation
 * 
 * @param arr_len 
 * @param array 
 */
void bubble_sort( int arr_len, int *array );

/**
 * @brief Selection Sort Algorithm implementation
 * 
 * @param arr_len 
 * @param array 
 */
void selection_sort( int arr_len, int *array );

/**
 * @brief Insertion Sort Algorithm implementation
 * 
 * @param arr_len 
 * @param array 
 */
void insertion_sort( int arr_len, int *array );

/**
 * @brief Quick Sort Algorithm implementation
 * 
 * @param lo 
 * @param hi 
 * @param array 
 */
void quick_sort(int lo, int hi, int *array);

#ifdef SORT_IMPLEMENTATION_H

void bubble_sort(int arr_len, int *array) 
{
    int i, j, aux;
    for(i = 0; i < arr_len; i++) 
    {
        for(j = i + 1; j < arr_len; j++) 
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

void selection_sort( int arr_len, int *array) 
{
    int i, j, min, aux;
    for(i = 0; i < arr_len; i++) 
    {
        min = i;
        for(j = i + 1; j < arr_len; j++) 
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

void insertion_sort(int arr_len, int *array) 
{
    int i, j, aux;
    for(i = 1; i < arr_len; i++) 
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

void quick_sort(int low, int high, int *array) 
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
        quick_sort(low, j + 1, array);
    } 
    if(i < high)
    {
        quick_sort(i, high, array);
    }
}

#endif
#endif