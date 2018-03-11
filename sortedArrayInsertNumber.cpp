/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use memory allocation techniques to allocate memory.

ProblemCode :SAIN
*/

#include <stdio.h>
#include <malloc.h>


int * insert(int * Arr, int len, int num, int p);

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int i;
	if (Arr == NULL || len < 0)
		return NULL;
	else
	{
		Arr = (int *)realloc(Arr, (len + 1)*sizeof(int));
		
			for (i = 0; i <= len; i++)
			{
				if (Arr[i] > num)
				{
					if (i == 0)
					{
						break;
					}
				}
				if (Arr[len - 1] < num)
				{
					i = len;
					break;
				}
				if (Arr[i - 1]<num && Arr[i]>num)

				{
					break;
				}
				
			}
			return insert(Arr, len, num, i);
	}
}


int * insert(int *Arr, int len, int num, int p){
	int i;
	for (i = len; i>p;i--)
	{
		Arr[i] = Arr[i - 1];
		
	}
	Arr[p] = num;
	len++;
	return Arr;
}