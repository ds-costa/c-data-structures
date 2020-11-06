/****************************************
*	TITLE: Recursive functions
*	AUTHOR: David S. Costa		
*	DESCRIPTTION: A few recursive functions. For stress tests.
*****************************************/

#ifndef RECURSIVES_H
#define RECURSIVES_H
int decimalToBinary( int value );
// Factorial of a number (!a)
int factorial( int value );
// Binomial coefficient is indexed by a pair of integers n ≥ k ≥ 0
int binomialCoefficient( int n, int k );
// GCD between two numbers
int greatestCommonDivisor( int n, int k );
// Return: n^k like pow() function of math.h
int power(int n, int k);
// Sum of all values of an array
int  arraySum(int array[], int array_size);
// Sum of first 'a' values
int serieSum( int a );
#endif