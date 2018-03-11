
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:

Problem Code :SC
*/

#include <stdio.h>

int index;

void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) {


	int count = 0;
	if (Arr != NULL&&len > 0){
		int i;
		for (i = 0; i < len; i++)
		{
			if (*(Arr + i) == score)
			{
				index = i;
			}
			else
			{
				count++;
			}
			if (count == len)
			{
				index = -1;
			}

		}

		if (index != -1)
		{
			int i, count = 0;
			for (i = 0; Arr[i] == score; i++)
				count++;
			if (count == len){
				*lessCount = 0;
				*moreCount = 0;
				return 0;
			}
			*lessCount = index;
			*moreCount = len - index - 1;
			return 0;
		}

		{

			int j;
			for (j = 0; j < len; j++)
			{
				if (Arr[j]>score)
				{
					break;
				}
			}

			*lessCount = j;
			*moreCount = len - j;

		}
	}
	return NULL;
}

