/* @JUDGE_ID: andrea 10168 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <math.h>


/*@
 * Definitions of External Functions 
 */
int  check_prime(int );
void find_prime(int , int[] , int* );


/*@
 * Implementations of External Functions 
 */
int check_prime(int num)
{
    int temp, i;

    if (num < 2)
        return 0;

    temp = sqrt(num);

    for (i = 2; i <= temp; i++) {
        if (num % i == 0)  
            return 0;
    }   

    return 1;
}

void find_primes(int upper_bound, int primes[], int* num_primes)
{
    int i, j;
    int count, temp;

    count = 0;

    for (i = 2; i <= upper_bound; i++) {

        temp = sqrt(i);

        for (j = 0; j < count && primes[j] <= temp; j++) {
            if (i % primes[j] == 0)  
                break;
        }   
    
        if (j == count || primes[j] > temp) 
            primes[count++] = i;
    }   

    *num_primes = count;

    return;
}

int primes[1 << 9];
int num_primes;

int find_four_primes(int N, int count)
{
	int i;
	int temp;

	temp = sqrt(N);

	if (count == 1) {

		if (N == 1) {
			return 0;
		}

		for (i = 0; i < num_primes && primes[i] <= temp; i++) {
			if (N % primes[i] == 0) {
				return 0;
			}
		}

		printf("%d", N);
		return 1;
	}

	for (i = 0; i < num_primes && primes[i] < N; i++) {
		if (find_four_primes(N - primes[i], count - 1) == 1) {
			printf(" %d", primes[i]);
			return 1;
		}
	}

	return 0;
}

int main()
{
	int N, temp;

	/* pre-calculate primes numbers */
	temp = sqrt(10000000);
	find_primes(temp, &primes[0], &num_primes);

	/* process input and find a summation of four primes */
	while (scanf("%d\n", &N) != EOF) {
		if (find_four_primes(N, 4) == 0) {
			puts("Impossible.");
		}
		else {
			printf("\n");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
