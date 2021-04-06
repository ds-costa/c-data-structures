/****************************************
*	TITLE: Sort functions
*	AUTHOR: David S. Costa		
*****************************************/

#ifndef SORT_H
#define SORT_H

/**
 * function: bubble_sort
 * Buble_sort implementation
 * @param arr_len, Array length
 * @param array, Integer array reference
 */
void bubble_sort( int arr_len, int *array );

/**
 * function: selection_sort
 * Selection sort implementation
 * @param arr_len, Array length
 * @param array, Integer array reference
 */
void selection_sort( int arr_len, int *array );

/**
 * function: insertion_sort
 * Insertion sort implementation
 * @param arr_len, Array length
 * @param array, Integer array reference
 */
void insertion_sort( int arr_len, int *array );

/**
 * function: quick_sort
 * Quick sort implementation
 * @param low, Array inferior limit. On function call: (low = 0) 
 * @param high, Array superior limit
 * @param array, Integer array reference
 */
void quick_sort(int lo, int hi, int *array);

#endif