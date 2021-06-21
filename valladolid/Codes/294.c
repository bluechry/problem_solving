/* @JUDGE_ID: andrea 294 C "Number Theory" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <math.h>

#define MAX	1000000000

int check_prime(int num)
{
	int i;
	int temp;

	temp = sqrt(num);
	for (i = 2; i <= temp; i++) {
		if (num % i == 0) {
			return 0;
		}
	} 

	return 1;
}

int get_num_divisors(int num, int prime_num[], int num_primes)
{
	int num_div, count;
	int i;

	num_div = 1;
	for (i = 0; i < num_primes && num > 1; i++) {
		count = 0;
		while (num % prime_num[i] == 0) {
			num /= prime_num[i];
			count++;
		}
		num_div *= (count + 1);
	}

	return num_div;
}

int main()
{
	int prime_num[4096], num_primes;
	int num_cases, high, low;
	int div, max_div, max_num;
	int i, temp;

	/* Pre-calcuate the prime numbers */
	temp = sqrt(MAX);
	for (num_primes = 0, i = 2; i <= temp; i++) {
		if (check_prime(i)) {
			prime_num[num_primes++] = i;
		}	
	} 

	/* Get # of divisors and find the maximum value */
	scanf("%d\n", &num_cases);
	while (num_cases-- > 0) {
		scanf("%d %d\n", &low, &high);
	
		max_div = 0, max_num = 0;		
		for (i = low; i <= high; i++) {
			div = get_num_divisors(i, prime_num, num_primes);
			if (div > max_div) {
				max_div = div;
				max_num = i;
			}	
		}

		printf("Between %d and %d, %d has a maximum of %d divisors.\n", low, high, max_num, max_div);
	}	

	return 0;
}
/* @END_OF_SOURCE_CODE */
