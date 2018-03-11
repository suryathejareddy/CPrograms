/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/

#include<stdio.h>
#include<string.h>
char KthIndexFromEnd(char *str, int K) {
	if (str == "" || str == NULL || K < 0 || K>strlen(str)){
		return '\0';
	}
	int cnt = 0;
	while (str[cnt] != '\0')
		cnt++;
	int k = cnt;
	if (k < K)
		return '\0';
	return str[(k - K) - 1];

}