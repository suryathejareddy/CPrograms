/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes
will be followed by ones and then twos.

You should only change the links and shouldnt swap the data. Basically no write operation should be done on data field.

INPUTS:  SLL head pointer
OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2
ERROR CASES:
NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

/*
Optional : For this function swapping data is allowed.Although this wont be tested on our end.
It is only for learning purpose.
*/
void sll_012_sort_swapData(struct node **head){

}

/*
This is the actual function. You are supposed to change only the links.
*/
void sll_012_sort(struct node **head)
{
	struct node node0, node1, node2;
	node0.next = NULL;
	node1.next = NULL;
	node2.next = NULL;
	struct node *current, *zero, *one, *two;
	zero = &node0;
	one = &node1;
	two = &node2;
	current = *head;
	while (current != NULL)
	{
		if (current->data == 0)
		{
			zero->next = current;
			zero = zero->next;
		}
		else if (current->data == 1)
		{
			one->next = current;
			one = one->next;
		}
		else
		{
			two->next = current;
			two = two->next;
		}
		current = current->next;
	}
	zero->next = (node1.next) ? (node1.next) : (node2.next);
	one->next = node2.next;
	two->next = NULL;
	*head = node0.next;

	return;
}

