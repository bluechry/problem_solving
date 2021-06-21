/* @JUDGE_ID: andrea 406 C "Number Theory" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <math.h>

int check_prime(int num)
{
	int temp, i;

	if (num == 1) {
		return 1;
	}
	
	temp = sqrt(num);
	for (i = 2; i <= temp; i++) {
		if (num % i == 0) {
			return 0;
		}
	}	

	return 1;
}

void print_prime_cut(int primes[], int num_primes, int C)
{
	int i, j;

	C = (num_primes & 0x1) ? (2 * C - 1) : (2 * C);
	
	if (C >= num_primes) {
		i = 0;
		j = num_primes - 1;	
	}
	else if (num_primes & 0x1) {
		i = j = num_primes / 2;
		i = i - (C - 1) / 2;
		j = j + (C - 1) / 2;
	}
	else {
		i = num_primes / 2 - 1;
		j = num_primes / 2;
		i = i - (C - 2) / 2;
		j = j + (C - 2) / 2;
	}

	for ( ; i <= j; i++) {
		printf(" %d", primes[i]); 
	}
	printf("\n");
	
	return;
}

int main()
{
	int primes[1024], total_primes;
	int N, C;
	int i, count, num_primes;
	
	/* Pre-calculate primes */
	total_primes = 0;
	for (i = 1; i < 1000; i++) {
		if (check_prime(i)) {
			primes[total_primes++] = i;	
		}
	}

	/* input & output */
	while (scanf("%d %d\n", &N, &C) != EOF) {
		num_primes = 0;
		for (i = 0; i < total_primes && primes[i] <= N; i++) {
			num_primes++;
		}

		printf("%d %d:", N, C);		
		print_prime_cut(&primes[0], num_primes, C);
		printf("\n");
	}	

	return 0;
}
/* @END_OF_SOURCE_CODE */
