#include <string.h>

int stringLength(char *string) {
    long stringLen = 0;
    char *s = string;
    while( *s ) {
        stringLen++;
        s++;
    }
    return stringLen;
}

void stringCopy(char *destination, char *source) {
    while(*source) {
        (*destination) = (*source);
        destination++;
        source++;
    }
    (*destination) = '\0';
}

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

//Number of occurrences of the matchingString in the target string (Use: <string.h> for strlen())
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