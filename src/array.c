#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"

//Read values from the console to an entire array of one dimension
// void arr_scan_int(int arr_len, int *array) 
// {
//     int i;
//     for( i = 0 ; i < arr_len ; i++ ) 
//     {
//         printf("Array[%d] :: ", i);
//         scanf("%i", &array[i]);
//     }
// }
//Write on console an integer one dimentional array values
// void arr_print_int(int arr_len, int *array) 
// {
//     int i;
//     for( i = 0 ; i < arr_len ; i++ ) 
//     {
//         printf("(int) Array[%d] :: %d\n", i, array[i]);
//     }
// }


ARRAY_SCAN(int, "%d", array[i])
ARRAY_PRINT(int, "(int) Array[%d] :: [%d]\n", i , array[i])

ARRAY_SCAN(float, "%f", array[i])
ARRAY_PRINT(float, "(float) Array[%d] :: [%f]\n", i , array[i])

ARRAY_SCAN(double, "%lf", array[i])
ARRAY_PRINT(double, "(double) Array[%d] :: [%lf]\n", i , array[i])



//Fill an integer array with random numbers in an interval [low, high]
void arr_random_fill(int low, int high, int arr_len, int *arr) 
{
    int i;
    for(i = 0; i < arr_len; ++i) 
    {
        arr[i] = ( low + rand() % ( high - low + 1 ));
    }
}

//Shuffle an array  By: Richard Durstenfeld (1964) AND Ronald Fisher and Frank Yates (1938) 
void arr_shuffle(int arr_len, int *arr) 
{
    int i, j, aux;
	for(i = 0 ; i < arr_len ; i++) 
    {
		j = (rand() % arr_len);
		aux = arr[i];
		arr[i] = arr[j];
		arr[j] = aux;
	}
}

int arr_linear_search(int key, int arr_len, int *arr)
{
    int i;
    for(i = 0; i < arr_len; i++) 
    {
        if(arr[i] == key)
        {
            return i;
        }
    }
    return -1; 
}