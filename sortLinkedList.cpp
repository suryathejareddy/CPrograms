/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.

*/

#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int num;
	struct node *next;
};
//int* sort1(int *a,int l);
struct node * sortLinkedList(struct node *head) 
{
	int arr[100];
	int j, k, temp;
	int i=0,c=0;
	struct node *current=head;

	if (head != NULL)
	{
		do
		{
			arr[i] = current->num;
			current = current->next;
			i++;
			
		}	while (current != NULL);
		
	
		for (j = 0; j < i; j++)
		{
			for (k = j; k < i; k++)
			{
				if (arr[j]>arr[k])
				{
					temp = arr[j];
					arr[j] = arr[k];
					arr[k] = temp;

				}
			}
		}
		current = head;
		do
		{
			current->num = arr[c];
			c++;
		    current =current->next;
		} while (current != NULL);
		
		return head;
	}
	return NULL;
}
