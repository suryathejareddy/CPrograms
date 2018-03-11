/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

struct node {
	int num;
	struct node *next;
};
typedef struct node n;
struct node * removeEveryKthNode(struct node *head, int K)
{

	
	if (head != NULL&&K > 0)
	{
		if (K == 1)
		{
			n *next = head->next;
			delete (head);
			head = next;
			return NULL;
		}
		n *curr=head, *prev = NULL;
		int count = 0;
		while (curr != NULL)
		{
			count++;
			if (K == count)
			{
				delete(prev->next);
				prev->next = curr->next;
				count = 0;
			}
			if (count != 0)
			{
				prev = curr;
			}
			curr = curr->next;
		}
		return head;
	}
	return NULL;
}