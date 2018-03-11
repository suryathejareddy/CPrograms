/*
OVERVIEW: Given an Integer Array return the count of one's and two's in a new array of length two.
Ex: input: [1,2,2,1,2,1,2] 
	output: [3,4]
	where 3 is the count of 1's and 4 is the count of 2's

INPUTS: An Integer Array and length of the array 

OUTPUT: An Array with 1's count and 2's count

ERROR CASES: Return NULL for invalid inputs

Difficulty : Very Easy
*/

#include <stdio.h>
int* oneTwoCount(int* input, int length)
{
	int count1 = 0, count2 = 0;
	int i;
	if (length <= 0 || input == NULL)
	{
		return NULL;
	}
	for (i = 0; i < length; i++)
	{
		if (input[i] == 1)
		{
			count1++;
		}
		else if (input[i] == 2)
		{
			count2++;
		}
		else
		{
			return NULL;
		}
	}
	static int  output[2];
	output[0] = count1;
	output[1] = count2;
	return output;
}