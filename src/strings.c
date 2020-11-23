#include <string.h>

//My strlen function implementation
int stringLength(char *str) {
    long length = 0;
    char *s = str;
    while( *s ) {
        length++;
        s++;
    }
    return length;
}
//My strcpy function implementation
void stringCopy(char *destination, char *source) {
    while(*source) {
        (*destination) = (*source);
        destination++;
        source++;
    }
    (*destination) = '\0';
}
//My strcmp function implementation
int stringCompare(char *strOne, char *strTwo) {
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
//My strcat function implementation
void stringCatern(char *destination, char *source, int len) {
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
// Reverse a given string
void stringReverse(char *str) {
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
	}
}

//Number of occurrences of the matching string in the target string (Use: <string.h> for strlen())
int trivialMatch(char *matchingString, char *targetString) {
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

//Checks if a word is a palindrome (Use: <string.h> for strlen())
_Bool palindrome(char *str) {
    int length = strlen(str);
    for(int i = 0; i < length / 2; i++) {
        if(str[i] != str[(length - 1) - i])
            return 0;
    }
    return 1;
}