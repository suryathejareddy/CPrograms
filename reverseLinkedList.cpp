/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
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
		struct node *temp = head;
		int j = i - 1;
		while (j >= 0)
		{
			temp->num = a[j];
			j--;
			temp = temp->next;
		}
		return head;
	}
	return NULL;
}
