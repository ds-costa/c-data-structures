#ifndef ARRAY_H
#define ARRAY_H


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

/**
 * @brief Reads the contents of stdin and writes to the array 
 * 
 * @param arr_len 
 * @param array 
 */
void arr_scan( int arr_len, int *array );

/**
 * @brief Reads the contents of the array and writes to stdout
 * 
 * @param arr_len 
 * @param array 
 */
void arr_print( int arr_len, int *array );

/**
 * @brief Fills an array with random numbers in the inclusive range [high, low]
 * 
 * @param low 
 * @param high 
 * @param arr_len 
 * @param arr 
 */
void arr_random_fill(int low, int high, int arr_len, int *arr);

/**
 * @brief Shuffle an array. Original algo By: Richard Durstenfeld (1964) AND Ronald Fisher and Frank Yates (1938) 
 * 
 * @param arr_len 
 * @param arr 
 */
void arr_shuffle(int arr_len, int *arr);


/**
 * @brief Linear Search Algorithm implementation 
 * 
 * @param key 
 * @param arr_len 
 * @param arr 
 * @return int 
 */
int arr_linear_search(int key, int arr_len, int *arr);

/**
 * @brief Binary Search Algorithm implementation for sorted arrays
 * 
 * @param key 
 * @param arr_len 
 * @param arr 
 * @return int 
 */
int arr_binary_search(int key, int arr_len, int *arr);


#ifdef ARRAY_IMPLEMENTATION_H

void arr_scan(int arr_len, int *array) {
    int i;
    for(i = 0; i < arr_len; i++) {
        scanf("%d", &array[i]);
    }
}

void arr_print(int arr_len, int *array) {
	int i;
	printf("[ ");
    for(i = 0; i < arr_len; i++) {
		printf("%d, ", array[i]);
	}    
	printf("]\n");
}

void arr_random_fill(int low, int high, int arr_len, int *arr) 
{
    int i;
    for(i = 0; i < arr_len; ++i) {
        arr[i] = ( low + rand() % ( high - low + 1 ));
    }
}

void arr_shuffle(int arr_len, int *arr) {
    int i, j, aux;
	for(i = 0 ; i < arr_len ; i++) {
		j = (rand() % arr_len);
		aux = arr[i];
		arr[i] = arr[j];
		arr[j] = aux;
	}
}

int arr_linear_search(int key, int arr_len, int *arr) {
    int i;
    for(i = 0; i < arr_len; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1; 
}

int arr_binary_search(int key, int arr_len, int *arr) {
    int low = 0;
    int high = arr_len;
    int mid;

    while(low < high) {
    
        mid = (high + low) / 2;
        
        if(arr[mid] == key) {
            return mid;
        }
        
        if(arr[mid] < key) {
            low = mid;
        }

        else if(arr[mid] > key) {
            high = mid;
        }
    }   

    return -1;
}

#endif
#endif