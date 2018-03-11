/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES:

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
typedef struct node n;
struct node * numberToLinkedList(int N) {
	int arr[10];
	
	n *head,*current,*newnode;
	int i,j=0,k,flag;
	head = (n*)malloc(sizeof(n));
	
	head->next = NULL;
	flag = 0;
	//current = (n*)malloc(sizeof(n));
	
	//current->next = NULL; 
	if (N == 0)
	{
		head->num = N;
		return head;
	}
	if (N < 0)
	{
		N = (N*(-1));
	}
	while (N > 0)
	{
		i = N % 10;
		N = N / 10;
		arr[j] = i;
		j++;
		
	}
	for (k =(j-1) ; k>=0; k--)
	{
		if (flag==0)
		{
			
			head->num = arr[k];
			current = head;
			flag = 1;
		}

		else
		{
			newnode = (n*)malloc(sizeof(n));
			newnode->next = NULL;
			current->next = newnode;
			newnode->num = arr[k];
			current = newnode;
			

		}
	}
	
	return head;
	
}