/****************************************
*	TITLE: Sort functions
*	AUTHOR: David S. Costa		
*****************************************/

#ifndef SORT_H
#define SORT_H
// Bubble Sort
void bubbleSort( int array[], int arrayLenght );
//  Selection Sort
void selectionSort( int array[], int arrayLenght );
// Insertion Sort
void insertionSort( int array[], int arrayLenght );
// Quick Sort
void quickSort(int array[], int begin, int end);
//  Heap Sort
void heapSort(int *array, int arrayLenght);
void makeHeap(int *array, int begin, int end);
// Merge Sort
void mergeSort(int *array, int begin, int end);
void merge(int *array, int begin, int middle, int end);
#endif