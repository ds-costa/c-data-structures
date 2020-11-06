#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Read values from the console to an entire array of one dimension
void scanIntArray( int array[], int arrayLenght ) {
    int i;
    for( i = 0 ; i < arrayLenght ; i++ ) {
        printf("Array[%d] :: ", i);
        scanf("%i", &array[i]);
    }
}

//Write on console an integer one dimentional array values
void printIntArray( int *array, int arrayLenght ) {
    int i;
    for( i = 0 ; i < arrayLenght ; i++ ) {
        printf("(int) Array[%d] :: %d\n", i, array[i]);
    }
}

void scanFloatArray( float *array, int arrayLenght ) {
    int i;
    for( i = 0 ; i < arrayLenght ; i++ ) {
        printf("Array[%d] :: ", i);
        scanf("%f", &array[i]);
    }
}
void printFloatArray( float *array, int arrayLenght ) {
    int i;
    for( i = 0 ; i < arrayLenght ; i++ ) {
        printf("(float) Array[%d] :: %.2f\n", i, array[i]);
    }
}

void scanDoubleArray( double *array, int arrayLenght ) {
    int i;
    for( i = 0 ; i < arrayLenght ; i++ ) {
        printf("Array[%d] :: ", i);
        scanf("%lf", &array[i]);
    }
}
void printDoubleArray( double *array, int arrayLenght ) {
    int i;
    for( i = 0 ; i < arrayLenght ; i++ ) {
        printf("(float) Array[%d] :: %.2lf\n", i, array[i]);
    }
}

//Fill an integer array with random numbers in an interval [a, b]
void randomValuesFillArray( int *array, int arrayLenght, int inferiorLimit, int superiorLimit ) {
    int i;
    for( i = 0; i < arrayLenght; i++ ) {
        array[i] = ( inferiorLimit + rand() % ( superiorLimit - inferiorLimit + 1 ));
    }
}

//Shuffle an array  By: Richard Durstenfeld (1964) AND Ronald Fisher and Frank Yates (1938) 
void fisherYattesShuffle(int *array, int arrayLenght) {
  int i, j, aux;
	for(i = 0 ; i < arrayLenght ; i++) {
		j = (rand() % arrayLenght);
		aux = array[i];
		array[i] = array[j];
		array[j] = aux;
	}
}

int linearSearch(int *array, int arrayLenght, int item) {
    int i;
    for(i = 0; i < arrayLenght; i++) {
        if(array[i] == item)
            return i;
    }
    return -1; 
}