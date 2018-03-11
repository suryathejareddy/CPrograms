/*
Given a number ending in a 3 has a multiple which consists only of ones.
Eg. 3 has 111 and 13 has 111111 etc.

You have to write a C function which will take a number ending in 3
and find the number the multiple consisting of all ones.
You need to return the number of 1s in that final Number .

Note that the traditonal method of finding 
multiples of current number and checking if it has all ones wont work 
as the multiple can be out of Interger Range ,but the count may not be.

return -1 for error cases

INPUT: Single integer number

OUTPUT: count of one's in the answer obtained

ERROR CASES: return -1 

Sample Input : 3
Output : 3 (111 is the multiple )
*/

int countOnes(int number)
{
	if (number < 0){
		number = number*(-1);
	}
	if (number % 10 != 3 || number<0){
		return -1;
	}
	long int count = 1, temp = 1;
	while (temp != 0)
	{
		temp = (temp * 10 + 1) % number;
		count++;
	}
	return count;
}

