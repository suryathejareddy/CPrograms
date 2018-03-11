/*
Here you will compare 2 searching algorithms.

LinearSearch and BinarySearch

Question :
Given an Array and its length and a key element, return the index (Where key is found) if key is found in array
or -1 if key is not found.

Sample Input : 
[1,2,3,4,5] Key : 4, Returns 3
[0,49,22] Key : 212, Returns -1

Observations: (Write down what you observed here, Run for various variations):

Linear Search:

Binary Search :

Conclusion :
*/
#include<stdio.h>
int binary_search(int *list, int lo, int hi, int key);
int linearSearch(int *arr, int len, int key)
{
	int i;
	if (arr != NULL&&len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (arr[i] == key)
			{
				break;

			}
		}
		return i;
	}
	return -1;
}
int binarySearch(int *arr, int len, int key)
{
	
	///Use this function as wrapper function,if you are implementing bs recursively.
	if (arr != NULL&&len > 0)
	{
		return binary_search(arr, 0, len, key);
	}
	return -1;
}
int binary_search(int *list, int lo, int hi, int key)
{
	 int mid;

	
		mid = (lo + hi) / 2;
		if (list[mid] == key)
		{
			return mid;
		}
		else if (list[mid] > key)
		{
		return	binary_search(list, lo, mid - 1, key);
		}
		else if (list[mid]<key)
		{
			return binary_search(list, mid + 1, hi, key);
		}
		else
		{
			return -1;
		}
	
}