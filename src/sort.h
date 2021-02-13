/****************************************
*	TITLE: Sort functions
*	AUTHOR: David S. Costa		
*****************************************/

#ifndef SORT_H
#define SORT_H
// Bubble Sort
void bubbleSort( int arrayLenght, int *array );
//  Selection Sort
void selectionSort( int arrayLenght, int *array );
// Insertion Sort
void insertionSort( int arrayLenght, int *array );
// Quick Sort
void quickSort(int begin, int end, int *array);

// //  Heap Sort
// void heapSort(int *array, int arrayLenght);
// void makeHeap(int *array, int begin, int end);
// // Merge Sort
// void mergeSort(int *array, int begin, int end);
// void merge(int *array, int begin, int middle, int end);
#endif