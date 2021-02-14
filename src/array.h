#ifndef ARRAY_H
#define ARRAY_H

#define ARRAY_SCAN(TYPE, scan_format, args) \
    void array_scan_##TYPE(int arr_len, TYPE *array) \
    { \
       int i; \
       for( i = 0; i < arr_len; i++ ) \
       { \
           scanf( scan_format, &array[i] ); \
       } \
    }

#define ARRAY_PRINT(TYPE, print_format, index, value) \
    void array_print_##TYPE(int arr_len,  TYPE *array) \
    { \
        int i; \
        for( i = 0; i < arr_len; i++ ) \
        { \
            printf(print_format, index, value); \
        } \
        printf("\n\n"); \
    }

#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))


//Write an array of integers
void array_scan_int( int arr_len, int *array );
//Write an array of integers
void array_print_int( int arr_len, int *array );

void array_scan_float( int arr_len, float *array );
void array_print_float( int arr_len, float *array );

void array_scan_double( int arr_len, double *array );
void array_print_double( int arr_len, double *array );


//Shuffle an array  By: Richard Durstenfeld (1964) and Ronald Fisher and Frank Yates (1938) 
void fisherYattesShuffle(int array[], int arr_len);
//
int linearSearch(int *array, int arr_len, int item);

#endif