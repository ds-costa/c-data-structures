#ifndef ARRAY_H
#define ARRAY_H

//Write an array of integers
void scanIntArray( int *array, int arrayLenght );
//Write an array of integers
void printIntArray( int *array, int arrayLenght );

void scanFloatArray( float *array, int arrayLenght );
void printFloatArray( float *array, int arrayLenght );

void scanDoubleArray( double *array, int arrayLenght );
void printDoubleArray( double *array, int arrayLenght );


//Shuffle an array  By: Richard Durstenfeld (1964) and Ronald Fisher and Frank Yates (1938) 
void fisherYattesShuffle(int array[], int arrayLenght);
//
int linearSearch(int *array, int arrayLenght, int item);

#endif