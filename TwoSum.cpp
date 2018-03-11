/*
Given an array of integers, return the two numbers such that they add up to a specific target.

You may assume that each input will have exactly one solution. Return NULL for invalid inputs

Given nums = [1, 20, 2, 4], target = 24,

Because nums[1] + nums[3] = 20 + 4 = 24,
return [4, 20]. (Always the first number should be less in final answer)

If target is 5 ,Return [1,4]
If target is 22 ,return [2,20]

Note :
Return_Array[0] should always be less than/equal to Return_Array[1]

Constraints :
len <100000
-100000< nums[i] <100000

Question Source Link : https://leetcode.com/problems/two-sum/
We Picked this standard problem from Online , as its a very famous one and you will get habituated on solving on
Leetcode .

You need to solve this question in 3 ways.And measure time for each way.

Observations: (Write down what you observed here):

Way 1 :

Way 2 :

Way 3:

Conclusion :
*/
#include <stdio.h>
#include <stdlib.h>

/*
Take each element, Sum with all other elements.
Repeat it with all elements.

What is the complexity of this method ? __________
*/
void quicksort(int *number, int first, int last);
int search( int key,int len);
int* sumoftwoBF(int *nums, int target, int len){
	static int output[2];
	long i, j;
	
	if (nums != NULL&&len > 0)
	{
		for (i = 0; i < len; i++)
		{
			for (j = 0; j < len; j++)
			{
				if (nums[i] + nums[j] == target&&nums[i] < nums[j])
				{
					
					output[0] = nums[i];
					output[1] = nums[j];
					break;
				}


			
			}
			

			
		}
		return output;
	}
	return NULL;
}

/*
Sort the array first. Preferably using quicksort/mergesort. (nlogn)

Now the array is sorted, Can you do improve the above method.

Hint: 
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11. 

Lets say we added 3+12 first, whats the sum, Its 15 right ? Its greater than 11.So should we next add 
so that total sum will become less. 

What is the complexity of this method ? __________

*/

int* sumoftwoSortAndSearch(int *nums, int target, int len){
	//Sort the array

	static int  otpt[2];
	
	int   x=0, y=len-1;
	if (nums == NULL || len <= 0)
	{
		return NULL;
	}
	else
	{
		quicksort(nums, 0, len - 1);
		
		//Do the task
		

		while (x < y) {
			int a = nums[x] + nums[y];
			if (a < target)
			{
				++x;
			}
			else if (a > target) 
			{
				y--;
			}
			else {
				otpt[0] = nums[x];
				otpt[1] = nums[y];
				return otpt;
			}
		}
	}
}
void quicksort(int *number, int first, int last){
	int i, j, pivot, temp;

	if (first<last){
		pivot = first;
		i = first;
		j = last;

		while (i<j){
			while (number[i] <= number[pivot] && i<last)
				i++;
			while (number[j]>number[pivot])
				j--;
			if (i<j){
				temp = number[i];
				number[i] = number[j];
				number[j] = temp;
			}
		}

		temp = number[pivot];
		number[pivot] = number[j];
		number[j] = temp;
		quicksort(number, first, j - 1);
		quicksort(number, j + 1, last);

	}
}
/*

Array contains only integers from 1-100; Can you use this range restriction and an extra array to 
find 2Sum even more faster

Hint:
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11.

If we are at 3, What number we need to tell that 3 is in final answer? 8 right (11-3 = 8). So some how we need to find a way
to know whether 8 is already in the array or not.As of now we dont know that, we will store 3 somewhere
(Which can be accesible in O(1)) and move to next element. 4 is there, we need to know whether array has 7 or not.(11-4 =7)
We dont know that yet, we move on ...we will store 4 somewhere now.

We go on till 7(4th element). We reach here we require 4 (11-7 = 4) .We already know 4 is present in array. (With O(1)).
We immediately return the answer. Think and discuss with your friends.

You are expected to solve this method in O(n)
*/
int duplicate[1000];
int* sumoftwoExtraArray(int *nums, int target, int len) {
	
	if (nums == NULL || len <= 0)
	{
		return NULL;
	}


	else
	{
		
		quicksort(nums, 0, len - 1);
		static int outpt[2];
		 int  i, x;
		//Initialise the array

		//Do the task
		for (i = 0; i < len; i++)
		{
			duplicate[i] = nums[i];
			x = target - nums[i];
			int a = search(x,len);

			if (a != -1)
			{
				if (nums[i] < duplicate[a])
				{
					outpt[0] = nums[i];
					outpt[1] = duplicate[a];
					break;
				}
				else
				{
					outpt[1] = nums[i];
					outpt[0] = duplicate[a];
					break;

				}
			}

		}
		return outpt;

	}

}
int search(int key, int len)
{
	int z;
	for (z = 0; z < len; z++)
	{
		if (duplicate[z] == key)
		{
			return z;
		}
	}
	return -1;

}