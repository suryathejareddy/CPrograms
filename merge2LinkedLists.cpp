/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>
int a[100];
void sort(int l);
struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 != NULL || head2 != NULL)
	{
		int i,j,k;
		struct node *current = head1;
		for (i = 0; current != NULL; i++)
		{
			if (current == NULL)
			{
				break;
			}
			a[i] = current->num;
			current = current->next;
			
		}
		current = head2;
		for (k = i; current != NULL; k++)
		{
			if (current == NULL)
			{
				break;
			}
			a[k] = current->num;
			current = current->next;
		}
		
		sort(k);
		struct node *n;
		
		n = (struct node *)malloc(sizeof(struct node));
		n->num = a[0];
		n->next = NULL;
		struct node *h = n;
		for (j = 1; j < k; j++)
		{
			struct node * newn;
			newn = (struct node *)malloc(sizeof(struct node));
			newn->num = a[j];
			newn->next = NULL;
			n->next = newn;
			n = n->next;
			
		}

		return h;
		

	}
	return NULL;
}
void sort(int l)
{
	int i, j;
	for (i = 0; i < l; i++)
	{
		for (j = i+1; j < l; j++)
		{
			if (a[i]>=a[j])
			{
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}