/*
OVERVIEW: 
1)Write a function which takes a decimal number as input and returns the octal number for decimalToOctal().
E.g.: decimalToOctal(10) returns 12.

2)Write a function which takes a fractional decimal number as input and returns the octal number for decimalToOctalFraction()
until precision two
E.g.: decimalToOctal(6.06) returns 6.03

INPUTS: Single decimal number num;

OUTPUT: Octal value of the Decimal Number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>

int decimalToOctal(int num)
{
	int temp = num, count = -1, octal = 0;
	while (temp > 0){
		count++;
		int i = temp % 8, j;
		temp = temp / 8;
		for (j = 1; j <= count; j++)
			i = i * 10;
		octal = octal + i;
	}
	return octal;
}

float decimalToOctalFraction(float num)
{
	int decimal = num;
	int octaldecimal = decimalToOctal(decimal);
	float fractional = num - decimal;
	int fraction = 0, count = 0, i;
	for (i = 0; i < 10; i++){
		if (fractional == 0){
			break;
		}
		count++;
		int df = fractional * 8;
		fraction = fraction * 10 + df;
		fractional = fractional * 8 - df;
	}
	float of = fraction;
	for (i = 0; i < count; i++){
		of = of / 10;
	}
	float octalfraction = octaldecimal + of;
	return octalfraction;
}