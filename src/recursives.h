/****************************************
*	TITLE: Recursive functions
*	AUTHOR: David S. Costa		
*	DESCRIPTTION: A few recursive functions. For stress tests.
*****************************************/

#ifndef RECURSIVES_H
#define RECURSIVES_H

/**
 * function: dec_to_bin
 * Convert a decimal number to a binary
 * @param value, integer decimal value
 * return: converted binary value 
 */
int dec_to_bin( int value );

/**
 * function: factorial
 * Factorial of a number (!value)
 * @param value, integer decimal value
 * return: factorial value 
 */
int factorial( int value );

/**
 * function: binomial_coefficient
 * Binomial coefficient is indexed by a pair of integers n ≥ k ≥ 0
 * @param n, integer decimal value
 * @param k, integer decimal value 
 * return: binomial number
 */
int binomial_coefficient( int n, int k );

/**
 * function: greatest_common_divisor
 * GCD between two numbers
 * @param n, integer decimal value
 * @param k, integer decimal value 
 * return: GDC between n and k
 */
int greatest_common_divisor( int n, int k );

/**
 * function: power
 * @param n, integer decimal value
 * @param k, integer decimal value 
 * return: n^k like pow() function of math.h
 */
int power(int n, int k);

/**
 * function: serie_sum
 * Sum of first 'a' values
 * @param a, integer decimal value
 * return: Serie sum
 */
int serie_sum( int a );

#endif