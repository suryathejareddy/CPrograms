
/*
OVERVIEW: Given an array of integers find the maximum possible sum formed by a positive and the negative
integer in the array.
Ex: input: [1, 9, 8, 2, 3, -1,-10,-5] output: 8 (formed by 9 and -1) 

INPUTS: An Integer array and the length of the array

OUTPUT: Maximum possible sum formed by a positive and the negative integer in the array

ERROR CASES: Return 0 for the invalid inputs

NOTES:
*/

#include <stdio.h>

int maxPosNegSum(int* input, int length)
{
	int i, j, max = input[0], min = 0;
	if (input == NULL || length <= 0)
	{
		return 0;
	}
	for (i = 0; i < length; i++){
		if (input[i] >= max&&input[i] >= 0){
			max = input[i];
		}
		else
		{
			min = input[i];
		}
	}
	for (j = 0; j < length; j++)
	{
		if (input[j] < 0 && min <= input[j])
		{
			min = input[j];
		}
	}
	if (max < 0 || min >= 0)
	{
		return 0;
	}
	return (min + max);
}