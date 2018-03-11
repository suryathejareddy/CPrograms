/*
Given a value n

1. return nth Fibonacci number for the function nthFibonacci(int)
	EX: 0 for n=1 and 1 for n=2


2. return nth prime number for the function nthPrime(int)
	EX: 2 for n=1 and 3 for n=2

INPUTS: single integer n

OUTPUTS: nth Fibonacci number for nthFibonacci() 
		 nth prime number for nthPrime()

ERROR CASES: return -1 for the error cases
*/

int nthFibonacci(int n)
{
	int current = 1, previous = 0, i, temp;
	if (n <= 0){
		return -1;
	}
	if (n == 1)
		return previous;
	if (n == 2)
		return current;
	for (i = 3; i <= n; i++){
		temp = current;
		current = previous + current;
		previous = temp;
	}
	return current;
}

int nthPrime(int num)
{
	if (num <= 0)
		return -1;
	int i, count = 1, temp = 2;
	while (count <= num){
		for (i = 2; i <= temp / 2; i++){
			if (temp%i == 0){
				break;
			}
		}
		if (i == ((temp / 2) + 1)){
			count++;
		}
		temp++;
	}
	return temp - 1;
}