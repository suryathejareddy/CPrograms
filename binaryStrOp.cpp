/*

ProblemCODE : BINARYSTROP
Difficulty : Medium
Marks : 15

Given two binary numbers in form of strings and
a string representing "AND", "OR", "NOR" or "XOR". Return the output string which forms by doing the specified operation on those 2 strings .


Ex:	Input: "101", "111", op =  "OR"
Output: "111"


Ex:	Input: "10101", "1111", op =  "AND"
Output: "00101"

Ex:	Input: "0111", "1010", op =  "XOR"
Output: "0010"

Ex:	Input: "0011", "1010", op =  "NOR"
Output: "0100"

Note :
In the above representations ,Write those strings on a paper ,you will understand them better . [Align them to the Right]
If 1 string length is less than other ,you need to consider missing letters as 0's ie "1111" AND "1" is same as "1111" AND "0001".
Ie if a String is "" ,you should consider it as All 0's .This dosent not apply if String is NULL.

Reference : http://www.bristolwatch.com/pport/pics/logic_table.gif [For AND,OR,XOR]
For NOR : http://www.circuitstoday.com/wp-content/uploads/2010/04/2-Input-NOR-Gate-Truth-Table.jpg

Contraints :
String length < 50.
For 50% of TestCases ,only AND/OR operations will be given .

Difficulty : Medium

*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int lenght(char *s){
	int i = 0;
	while (s[i] != '\0')
		i++;
	return i;
}
char *performOperation(char *str1, char *str2, char *operation){
	if (str1 == NULL || str2 == NULL || operation == NULL)
		return NULL;
	int i = lenght(str1) - 1;
	int j = lenght(str2) - 1;
	int loc, dif;
	if (i < j){
		loc = j;
		dif = j - i;
	}
	else{
		loc = i;
		dif = i - j;
	}
	static char return_array[200];
	char s1[200], s2[200];
	int k = loc;
	while (k >= 0){
		if (i < 0){
			s1[k] = '0';
		}
		else{
			s1[k] = str1[i];
			i--;
		}
		if (j < 0){
			s2[k] = '0';
		}
		else{
			s2[k] = str2[j];
			j--;
		}
		k--;
	}
	s1[loc + 1] = '\0';
	s2[loc + 1] = '\0';
	int choice = -1;
	int oi = 0, val = 0;
	while (operation[oi] != '\0'){
		if (operation[oi] > 64 && operation[oi] < 91)
			val = val + (operation[oi] - '0');
		oi++;
	}
	int max = loc;
	if (val == 67)
		choice = 1;
	else if (val == 65)
		choice = 2;
	else if (val == 105)
		choice = 3;
	else if (val == 95)
		choice = 4;
	else
		return NULL;
	switch (choice)
	{
	case 1:
		while (loc >= 0){
			if (s1[loc] == '0' || s2[loc] == '0' || s1[loc] == '1' || s2[loc] == '1'){
				if (s1[loc] == s2[loc] && s1[loc] == '1')
					return_array[loc] = '1';
				else
					return_array[loc] = '0';
				loc--;
			}
			else
				return NULL;
		}
		break;
	case 2:
		while (loc >= 0){
			if (s1[loc] == '0' || s2[loc] == '0' || s1[loc] == '1' || s2[loc] == '1'){
				if (s1[loc] == s2[loc] && s1[loc] == '0')
					return_array[loc] = '0';
				else
					return_array[loc] = '1';
				loc--;
			}
			else
				return NULL;
		}
		break;
	case 3:
		while (loc >= 0){
			if (s1[loc] == '0' || s2[loc] == '0' || s1[loc] == '1' || s2[loc] == '1'){
				if (s1[loc] == s2[loc])
					return_array[loc] = '0';
				else
					return_array[loc] = '1';
				loc--;
			}
			else
				return NULL;
		}
		break;
	case 4:
		while (loc >= 0){
			if (s1[loc] == '0' || s2[loc] == '0' || s1[loc] == '1' || s2[loc] == '1'){
				if (s1[loc] == s2[loc] && s1[loc] == '0')
					return_array[loc] = '1';
				else
					return_array[loc] = '0';
				loc--;
			}
			else
				return NULL;
		}
		break;

	}
	return_array[max + 1] = '\0';

	return return_array;
}








