
/**
 * function: dec_to_bin
 * Convert a decimal number to a binary
 * @param value, integer decimal value
 * return: converted binary value 
 */
int dec_to_bin( int value ) {
	if(value == 1 || value == 0) {
        return value;
	}
	return  ( 10 * dec_to_bin( value / 2 ) + value % 2 );   	
}

/**
 * function: factorial
 * Factorial of a number (!value)
 * @param value, integer decimal value
 * return: factorial value 
 */
int factorial( int value ) {
	if( value < 0 ) {
        return -1;
	}
    else if(value == 0) {
        return 1;
	} 
	return ( value * factorial( value - 1 ));
}

/**
 * function: binomial_coefficient
 * Binomial coefficient is indexed by a pair of integers n ≥ k ≥ 0
 * @param n, integer decimal value
 * @param k, integer decimal value 
 * return: binomial number
 */
int binomial_coefficient( int n, int k ) {
	return factorial(n) / ( factorial(k) * factorial( n - k )); // ( a! / (b! * (a - b)! ))
}

/**
 * function: greatest_common_divisor
 * GCD between two numbers
 * @param n, integer decimal value
 * @param k, integer decimal value 
 * return: GDC between n and k
 */
int greatest_common_divisor( int n, int k ) {
	if( n == k || !k )
		return n;
	return (0 + greatest_common_divisor( k, n % k ));
}

/**
 * function: power
 * @param n, integer decimal value
 * @param k, integer decimal value 
 * return: n^k like pow() function of math.h
 */
int power(int n, int k) {
	if( !k )
		return 1;
	return n * power( n, k - 1 );
}

// // Sum of all values of an array
// int  arraySum(int array[], int arrayLength) {
// 	if( arrayLength <= 0 ) 
// 		return 0;
// 	else if( arrayLength == 1 )
// 		return array[0];
// 	return  array[arrayLength - 1] + arraySum( array, arrayLength - 1 );
// }

// 

/**
 * function: serie_sum
 * Sum of first 'a' values
 * @param a, integer decimal value
 * return: Serie sum
 */
int serie_sum( int a ) {
	if( a == 1 ) 
		return 1;
	return a + serie_sum(a - 1);
}
