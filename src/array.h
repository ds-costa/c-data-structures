#ifndef ARRAY_H
#define ARRAY_H

#define ARRAY_SCAN(TYPE, scan_format, args) \
    void arr_scan_##TYPE(int arr_len, TYPE *array) \
    { \
       int i; \
       for( i = 0; i < arr_len; i++ ) \
       { \
           scanf( scan_format, &array[i] ); \
       } \
    }

#define ARRAY_PRINT(TYPE, print_format, index, value) \
    void arr_print_##TYPE(int arr_len,  TYPE *array) \
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
void arr_scan_int( int arr_len, int *array );
//Write an array of integers
void arr_print_int( int arr_len, int *array );

void arr_scan_float( int arr_len, float *array );
void arr_print_float( int arr_len, float *array );

void arr_scan_double( int arr_len, double *array );
void arr_print_double( int arr_len, double *array );



void arr_random_fill(int low, int high, int arr_len, int *arr);

//Shuffle an array  By: Richard Durstenfeld (1964) AND Ronald Fisher and Frank Yates (1938) 
void arr_shuffle(int arr_len, int *arr);

int arr_linear_search(int key, int arr_len, int *arr);

#endif