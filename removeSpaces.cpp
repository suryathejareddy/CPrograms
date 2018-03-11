/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

#include<stdio.h>
#include<string.h>
char removeSpaces(char *str) {
	if (str == NULL || str == ""){
		return '\0';
	}
	int i = 0;
	while (*(str + i) != '\0'){
		if (*(str + i) == ' '){
			strcpy(&str[i], &str[i + 1]);
			i--;
		}
		i++;
	}
	return '\0';
}