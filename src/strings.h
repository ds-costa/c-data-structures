/****************************************
*	TITLE: Strings functions
*	AUTHOR: David S. Costa		
*****************************************/

#ifndef STRINGS_H
#define STRINGS_H
int stringLength(char *string);
void stringCopy(char *destination, char *origin);
int stringCompare(char *strOne, char *strTwo);
void stringCatern(char *destination, char *source, int len);
int trivialMatch(char *matchingString, char *targetString);
_Bool palindrome(char *str);
#endif