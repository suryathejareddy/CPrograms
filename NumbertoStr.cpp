/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include<string.h>


void number_to_str(float number, char *str, int afterdecimal){
	int i = 0;
	float n = number;
	if (number < 0){
		n = n*(-1);
	}
	int temp = n;
	float a = n - temp;
	while (temp > 0){
		str[i] = (temp % 10) + '0';
		i++;
		temp = temp / 10;
	}
	int j;
	str[i] = '\0';
	str = strrev(str);
	if (afterdecimal>0){
		str[i++] = '.';
		for (j = 0; j < afterdecimal; j++){
			temp = a * 10;
			str[i] = ('0' + (temp % 10));
			i++;
			a = (a * 10) - temp;
		}
	}
	str[i] = '\0';
	i++;
	if (number<0){
		str[i] = '-';
		for (j = i; j>0; j--){
			char t = str[j];
			str[j] = str[j - 1];
			str[j - 1] = t;
		}
	}
	return;
}