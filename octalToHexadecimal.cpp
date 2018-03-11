/*
OVERVIEW:
1)Write a function which takes a octal number as input and returns the hexadecimal number for 
  octalToHexadecimal().
E.g.: octalToHexadecimal(10) returns 8.

2)Write a function which takes a fractional octal number as input and returns the hexadecimal number for 
octalToHexadecimalFraction() until precision two
E.g.: octalToHexadecimal(6.01) returns 6.04

INPUTS: Single octal number num;

OUTPUT: hexadecimal value of the octal number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>
#include<math.h>
int octalToHexadecimal(long int num)
{
	if (num<0)
		return 0;
	long int t = num, dec = 0, val = 0;
	int c = 0, i;
	while (t>0){
		int n = t % 10, pow = 1;
		c++;
		for (i = 1; i<c; i++)
			pow = pow * 8;
		dec = pow*n + dec;
		t = t / 10;
	}
	int count = -1, hexa = 0;
	t = dec;
	while (t > 0){
		count++;
		int i = t % 16, j;
		t = t / 16;
		for (j = 1; j <= count; j++)
			i = i * 10;
		hexa = hexa + i;
	}
	return hexa;
}


float octalToHexadecimalFraction(float num)
{
	return 0.0;
}
