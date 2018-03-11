/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three". 

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31

char ** commonWords(char *str1, char *str2) {
	if (str1 == NULL || str2 == NULL)
		return NULL;
	int i = 0, j, k, renum = 0, someword = 0;
	char t[31];
	char **retval = (char**)malloc(2 * sizeof(char*));
	for (i = 0; i < 2; i++){
		retval[i] = (char*)malloc(SIZE*(sizeof(char)));
	}
	i = 0;
	while (str1[i] != '\0'){
		if (str1[i] != ' '){
			j = 0;
			while (str1[i] != ' '&&str1[i] != '\0'){
				t[j] = str1[i];
				i++;
				j++;
			}
			t[j] = '\0';
			int max = j;
			k = 0;
			j = 0;
			while (str2[k] != '\0'){
				if (str2[k] != ' '&&str2[k] != '\0'){
					if (str2[k] == t[j]){
						k++;
						j++;
						if (j == max){
							j = 0;
							while (t[j] != '\0'){
								retval[renum][j] = t[j];
								j++;
							}
							retval[renum][j] = '\0';
							someword = 1;
							renum++;
						}
					}
					else{
						k++;
						j = 0;
					}
				}
				else{
					k++;
					j = 0;
				}
			}
		}
		else{
			i++;
			j = 0;
		}
	}
	if (someword == 0){
		return NULL;
	}
	return retval;
}