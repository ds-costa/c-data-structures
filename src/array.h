#ifndef ARRAY_H
#define ARRAY_H

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

/**
 * function: arr_scan_int
 * Writes to the array the (int) content read in the stdin
 * @param arr_len, Array length
 * @param array, Integer array reference
 */
void arr_scan_int( int arr_len, int *array );

/**
 * function: arr_print_int
 * Shows the contents of the (int) array in stdout
 * @param arr_len, Array length
 * @param array, Integer array reference
 */
void arr_print_int( int arr_len, int *array );

/**
 * function: arr_scan_float
 * Writes to the array the (float) content read in the stdin
 * @param arr_len, Array length
 * @param array, Integer array reference
 */
void arr_scan_float( int arr_len, float *array );

/**
 * function: arr_print_float
 * Shows the contents of the (float) array in stdout
 * @param arr_len, Array length
 * @param array, Integer array reference
 */
void arr_print_float( int arr_len, float *array );

/**
 * function: arr_scan_double
 * Writes to the array the (double) content read in the stdin
 * @param arr_len, Array length
 * @param array, Integer array reference
 */
void arr_scan_double( int arr_len, double *array );

/**
 * function: arr_print_double
 * Shows the contents of the (double) array in stdout
 * @param arr_len, Array length
 * @param array, Integer array reference
 */
void arr_print_double( int arr_len, double *array );

/**
 * function: arr_random_fill_int
 * Fill an integer array with random numbers in an interval [low, high]
 * @param low, inferior limit 
 * @param high, superior limit
 * @param arr_len, Array length
 * @param arr, Integer array reference
 */
void arr_random_fill_int(int low, int high, int arr_len, int *arr);

/**
 * function: arr_shuffle_int
 * Shuffle an array.  Original algo By: Richard Durstenfeld (1964) AND Ronald Fisher and Frank Yates (1938) 
 * @param arr_len, Array length
 * @param arr, Integer array reference
 */
void arr_shuffle_int(int arr_len, int *arr);

/**
 * function: arr_linear_search_int
 * Implementation of linear search algorithm
 * @param key, Target value
 * @param arr_len, Array length
 * @param arr, Integer array reference
 */
int arr_linear_search_int(int key, int arr_len, int *arr);

/**
 * function: arr_binary_search_int
 * Implementation of binary search algorithm for sorted arrays
 * @param key, Target value
 * @param arr_len, Array length
 * @param arr, Target integer array reference
 */
int arr_binary_search_int(int key, int arr_len, int *arr);

#endif