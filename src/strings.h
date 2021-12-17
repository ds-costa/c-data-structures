/****************************************
Functions for study purposes, preferably the standard compiler implementations
*****************************************/

#ifndef STRINGS_H
#define STRINGS_H

/**
 * @brief My strlen function implementation
 * 
 * @param str 
 * @return int 
 */
int str_length(char *str);

/**
 * @brief My strcpy function implementation
 * 
 * @param destination 
 * @param origin 
 */
void str_copy(char *destination, char *origin);

/**
 * @brief My strcmp function implementation
 * 
 * @param strOne 
 * @param strTwo 
 * @return int 
 */
int str_compare(char *strOne, char *strTwo);

/**
 * @brief My strcat implementation
 * 
 * @param destination 
 * @param source 
 * @param len 
 */
void str_concat(char *destination, char *source, int len);

/**
 * @brief Reverse a given string
 * 
 * @param str 
 */
void str_reverse(char *str);

/**
 * @brief Number of occurrences of the matching string in the target string (Note: <string.h> for strlen())
 * 
 * @param matchingString 
 * @param targetString 
 * @return int 
 */
int str_trivial_match(char *matchingString, char *targetString);

/**
 * @brief Checks if a word is a palindrome (Note: use <string.h> for strlen())
 * 
 * @param str 
 * @return int 
 */
int str_is_palindrome(char *str);


#ifdef STRINGS_IMPLEMENTATION_H

int str_length(char *str) {
    long length = 0;
    char *s = str;
    while( *s ) {
        length++;
        s++;
    }
    return length;
}

void str_copy(char *destination, char *source) {
    while(*source) {
        (*destination) = (*source);
        destination++;
        source++;
    }
    (*destination) = '\0';
}


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

int str_is_palindrome(char *str) {
    int length = strlen(str);
    for(int i = 0; i < length / 2; i++) {
        if(str[i] != str[(length - 1) - i])
            return 0;
    }
    return 1;
}

// Todo: memcpy implementation

#endif
#endif