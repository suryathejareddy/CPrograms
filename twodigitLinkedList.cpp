/*
OVERVIEW:  Given a single linked list (two digits as a node).Convert that to number


INPUTS:  SLL head pointer

OUTPUT: Create a number from the linked list given ,In each node there are two numbers ,digit1 and digit1 ,
So if the nodes are 12->34->56->78 , Final number would be 12345678 ( Integer)

ERROR CASES:

NOTES: Only Postive Numbers
*/

#include <stdio.h>

#include<stdlib.h>

struct twoDigitNode {
	int digit1;
	int digit2;
	struct twoDigitNode *next;
};

int convert_sll_2digit_to_int(struct twoDigitNode *head){
	int a[10];
	int i = 0;
	int j, sum = 0;
	char c[15];
	struct twoDigitNode *current=head;
	if (head != NULL)
	{
		do
		{
			a[i]=current->digit1;
			i++;
			a[i]=current->digit2 ;
			i++;
			current = current->next;
		}while (current != NULL);
		
		for (j = 0; j <i ; j++)
		{
			
			if (a[j] != 0)
			{
				sum = sum * 10;
				sum = sum + a[j];
			}
			
		
		}
		
		return sum;
	}
	return 0;
}
