
// Converting a Decimal number to a Binary
int decimalToBinary( int value ) {
	if( value == 1 || value == 0 ) 
        return value;
	return  ( 10 * decimalToBinary( value / 2 ) + value % 2 );   	
}

// Factorial of a number (!a)
int factorial( int value ) {
	if( value < 0 )
        return -1;
    else if(value == 0) 
        return 1;
	return ( value * factorial( value - 1 ));
}

// Binomial coefficient is indexed by a pair of integers n ≥ k ≥ 0
int binomialCoefficient( int n, int k ) {
	return factorial(n) / ( factorial(k) * factorial( n - k )); // ( a! / (b! * (a - b)! ))
}

// GCD between two numbers
int greatestCommonDivisor( int n, int k ) {
	if( n == k || !k )
		return n;
	return (0 + greatestCommonDivisor( k, n % k ));
}

// Return: n^k like pow() function of math.h
int power(int n, int k) {
	if( !k )
		return 1;
	return n * power( n, k - 1 );
}

// Sum of all values of an array
int  arraySum(int array[], int arrayLength) {
	if( arrayLength <= 0 ) 
		return 0;
	else if( arrayLength == 1 )
		return array[0];
	return  array[arrayLength - 1] + arraySum( array, arrayLength - 1 );
}

// Sum of first 'a' values
int serieSum( int a ) {
	if( a == 1 ) 
		return 1;
	return a + serieSum(a - 1);
}
