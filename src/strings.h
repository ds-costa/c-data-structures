/****************************************
*	TITLE: Strings functions
*	AUTHOR: David S. Costa		
*****************************************/

#ifndef STRINGS_H
#define STRINGS_H

/**
 * function: str_length
 * Return the length of a given string
 * @param str, string reference
 */
int str_length(char *str);

/**
 * function: str_copy
 * Copy the content of a source string to a destiny string 
 * @param destination, destination string reference
 * @param source, source string reference
 */
void str_copy(char *destination, char *origin);

/**
 * function: str_compare
 * Compare if two strings are the same
 * @param strOne, string reference
 * @param strTwo, string reference
 */
int str_compare(char *strOne, char *strTwo);

/**
 * function: str_concat
 * Concatenate the source string into the destination string
 * @param destination, destination string reference
 * @param source, source string reference
 * @param len
 */
void str_concat(char *destination, char *source, int len);

/**
 * function: str_reverse
 * Reverse a given string
 * @param str, string reference
 */
void str_reverse(char *str);

/**
 * function: str_trivial_match
 * Number of occurrences of the matching string in the target string (Use: <string.h> for strlen())
 * @param matchingString, string reference
 * @param targetString, string reference
 * return: number of matching occurrences
 */
int str_trivial_match(char *matchingString, char *targetString);

/**
 * function: str_is_palindrome
 * Checks if a word is a str_is_palindrome (Use: <string.h> for strlen())
 * @param str, string reference
 * return: string is a palindrome? (true | false)
 */
int str_is_palindrome(char *str);
#endif