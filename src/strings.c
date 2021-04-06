#include <string.h>

/**
 * strings.h lib
 * Functions for study purposes, always preferably standard libraries
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * /

/**
 * function: str_length
 * Return the length of a given string
 * @param str, string reference
 */
int str_length(char *str) {
    long length = 0;
    char *s = str;
    while( *s ) {
        length++;
        s++;
    }
    return length;
}

/**
 * function: str_copy
 * Copy the content of a source string to a destiny string 
 * @param destination, destination string reference
 * @param source, source string reference
 */
void str_copy(char *destination, char *source) {
    while(*source) {
        (*destination) = (*source);
        destination++;
        source++;
    }
    (*destination) = '\0';
}

/**
 * function: str_compare
 * Compare if two strings are the same
 * @param strOne, string reference
 * @param strTwo, string reference
 */
int str_compare(char *strOne, char *strTwo) {
    // (str1 == str2) (0) 
    // (str1 >!= str2) (1)
    // (str1 <!= str2) (-1) 
    char *s1 = strOne;
    char *s2 = strTwo;

    while(*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return ( *s1 > *s2 ) - ( *s2  > *s1 );
}

/**
 * function: str_concat
 * Concatenate the source string into the destination string
 * @param destination, destination string reference
 * @param source, source string reference
 * @param len
 */
void str_concat(char *destination, char *source, int len) {
    char *s1 = destination;
    char *s2 = source;
    int actual = 0;
    while(*s1) s1++;
    while(*s2 && (actual != len)) {
        (*s1) = (*s2);
        s1++;
        s2++;
        actual++;
    }
    (*s1) = '\0';
}

/**
 * function: str_reverse
 * Reverse a given string
 * @param str, string reference
 */
void str_reverse(char *str) {
	char aux;
	int len = strlen(str);
	for(int i = 0, j = len - 1; i < j; i++, j--) {
		//With aux variable
		aux = str[i];
		str[i] = str[j];
		str[j] = aux;
		//Optional no aux variable use
		// str[i] = str[i] + str[j];
		// str[j] = str[i] - str[j];
		// str[i] = str[i] - str[j];
		//Optional one index (j) use
		// aux = str[j];
		// str[j] = str[len - j - 1];
		// str[len - j - 1] = aux;
	}
}

/**
 * function: str_trivial_match
 * Number of occurrences of the matching string in the target string (Use: <string.h> for strlen())
 * @param matchingString, string reference
 * @param targetString, string reference
 * return: number of matching occurrences
 */
int str_trivial_match(char *matchingString, char *targetString) {
	int i, j, k;
	int matchingOccurrences = 0;
	int matchingStringLen = strlen(matchingString);
    int targetStringLen = strlen(targetString);
	
	for(k = matchingStringLen - 1; k < targetStringLen; k++) {
		for(i = matchingStringLen - 1, j = k; i >= 0; i--, j--) {
			if(matchingString[i] != targetString[j])
				break;	
		}
		if(i < 0) 
			matchingOccurrences++;	
	}
	return matchingOccurrences;	
}

/**
 * function: str_is_palindrome
 * Checks if a word is a str_is_palindrome (Use: <string.h> for strlen())
 * @param str, string reference
 * return: string is a palindrome? (true | false)
 */
int str_is_palindrome(char *str) {
    int length = strlen(str);
    for(int i = 0; i < length / 2; i++) {
        if(str[i] != str[(length - 1) - i])
            return 0;
    }
    return 1;
}
