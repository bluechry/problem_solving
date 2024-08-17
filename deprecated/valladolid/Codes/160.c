/* @JUDGE_ID: andrea ### C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <string.h>
#include <math.h>

int check_prime(int num)
{
	int i, temp;

	if (num <= 1) {
		return 0;
	}

	temp = sqrt(num);
	for (i = 2; i <= temp; i++) {
		if (num % i == 0) {
			return 0;
		}
	} 

	return 1;
}

int main()
{
	static int 	primes[128], prime_factor[128][128];
	int 		num_primes;
	int 		N, i, j, temp;

	/*
 	 * Pre-Calculate the primes <= 100
 	 */
	num_primes = 0;
	for (i = 2; i <= 100; i++) {
		if (check_prime(i) == 1) {
			primes[num_primes++] = i;
		}	
	}

	/*
	 * Pre-Prime Factorization of N! (2 <= N <= 100)
	 */
	for (i = 2; i <= 100; i++) {
		
		memcpy(&prime_factor[i][0], &prime_factor[i - 1][0], sizeof(int) * 128);

		temp = i;	
		for (j = 0; j < num_primes & temp > 0; j++) {
			while (temp % primes[j] == 0) {
				prime_factor[i][primes[j]]++;
				temp /= primes[j];
			}
		}
	}

	#if 0
	/*
 	 * Dump Prime Factorization of N!
 	 */
	for (i = 2; i <= 100; i++) {
		printf("[%d] = ", i);

		for (j = 0; j < num_primes && primes[j] <= i; j++) {
			printf(" %d", prime_factor[i][primes[j]]);
		}
		printf("\n");
	}
	#endif

	/*
 	 * Input & Output
 	 */
	while (scanf("%d\n", &N) == 1 && N != 0) {
	
		printf("%3d! =", N);
		for (i = 0; i < num_primes && primes[i] <= N; i++) {
			if (i > 0 && i % 15 == 0) {
			printf("\n      ");
			}
			printf("%3d", prime_factor[N][primes[i]]);
		}
		printf("\n");
	}
	
	return 0;
}
/* @END_OF_SOURCE_CODE */
