/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>
#include<stdio.h>
#include<malloc.h>

char * get_last_word(char * str){
	if (str == NULL)
		return NULL;
	if (str == "")
		return "";
	int len = 0;
	while (str[len] != '\0')
		len++;
	int i, j;
	i = j = -1;
	int gotachar = 0;
	len = len - 1;
	while (len >= 0){
		if (str[len] == ' '){
			if (gotachar == 1){
				i = len + 1;
				break;
			}
		}
		else{
			if (gotachar == 0)
				j = len;
			gotachar = 1;

		}
		len--;
	}
	if (i == -1 && j != -1)
		return str;
	if (i != -1 && j != -1){
		int k = 0;
		char *return_string = (char*)malloc((j - i + 1)*sizeof(char));
		for (k = 0; (k + i) <= j; k++){
			return_string[k] = str[k + i];
		}
		return_string[k] = '\0';
		return return_string;
	}
	return "";
}