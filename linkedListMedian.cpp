/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {

	struct node *current = head;
	int a[15], i = 0;
	if (head != NULL)
	{
		while (current != NULL)
		{
			a[i] = current->num;
			i++;
			current = current->next;

		}
		if (i % 2 == 0)
		{
			int avg = a[(i - 1) / 2] + a[((i - 1) / 2) + 1];
			avg = avg / 2;
			return avg;
		}
		else
			return a[i / 2];
	}
	return -1;
}
