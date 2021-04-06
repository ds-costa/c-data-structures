#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"

/**
 * function: arr_scan_int
 * Writes to the array the (int) content read in the stdin
 * @param arr_len, Array length
 * @param array, Integer array reference
 */
void arr_scan_int(int arr_len, int *array) {
    int i;
    for(i = 0; i < arr_len; i++) {
        scanf("%d", &array[i]);
    }
}

/**
 * function: arr_print_int
 * Shows the contents of the (int) array in stdout
 * @param arr_len, Array length
 * @param array, Integer array reference
 */
void arr_print_int(int arr_len, int *array) {
	int i;
	printf("[ ");
    for(i = 0; i < arr_len; i++) {
		printf("%d ", array[i]);
	}    
	printf("]\n");
}

/**
 * function: arr_scan_float
 * Writes to the array the (float) content read in the stdin
 * @param arr_len, Array length
 * @param array, Integer array reference
 */
void arr_scan_float(int arr_len, float *array) {
    int i;
    for(i = 0; i < arr_len; i++) {
        scanf("%f", &array[i]);
    }
}

/**
 * function: arr_print_float
 * Shows the contents of the (float) array in stdout
 * @param arr_len, Array length
 * @param array, Integer array reference
 */
void arr_print_float(int arr_len, float *array) {
	int i;
	printf("[ ");
    for(i = 0; i < arr_len; i++) {
		printf("%f ", array[i]);
	}    
	printf("]\n");
}

/**
 * function: arr_scan_double
 * Writes to the array the (double) content read in the stdin
 * @param arr_len, Array length
 * @param array, Integer array reference
 */
void arr_scan_double(int arr_len, double *array) {
    int i;
    for(i = 0; i < arr_len; i++) {
        scanf("%lf", &array[i]);
    }
}

/**
 * function: arr_print_double
 * Shows the contents of the (double) array in stdout
 * @param arr_len, Array length
 * @param array, Integer array reference
 */
void arr_print_double(int arr_len, double *array) {
	int i;
	printf("[ ");
    for(i = 0; i < arr_len; i++) {
		printf("%lf ", array[i]);
	}    
	printf("]\n");
}

/**
 * function: arr_random_fill_int
 * Fill an integer array with random numbers in an interval [low, high]
 * @param low, inferior limit 
 * @param high, superior limit
 * @param arr_len, Array length
 * @param arr, Integer array reference
 */
void arr_random_fill_int(int low, int high, int arr_len, int *arr) 
{
    int i;
    for(i = 0; i < arr_len; ++i) 
    {
        arr[i] = ( low + rand() % ( high - low + 1 ));
    }
}

/**
 * function: arr_shuffle_int
 * Shuffle an array.  Original algo By: Richard Durstenfeld (1964) AND Ronald Fisher and Frank Yates (1938) 
 * @param arr_len, Array length
 * @param arr, Integer array reference
 */
void arr_shuffle_int(int arr_len, int *arr) 
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

/**
 * function: arr_linear_search_int
 * Implementation of linear search algorithm
 * @param key, Target value
 * @param arr_len, Array length
 * @param arr, Integer array reference
 */
int arr_linear_search_int(int key, int arr_len, int *arr)
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