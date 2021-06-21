/* @JUDGE_ID: andrea 583 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <math.h>

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

int main()
{
	int primes[5 * 1 << 10], num_primes;
	int num, temp, i;

	/* pre-calculate the primes less than sqrt(2 ^ 31) */
	find_primes(sqrt((1U << 31) - 1), primes, &num_primes);


	/* while valid input */
	while (scanf("%d\n", &num) != EOF && num != 0) {
	
		printf("%d =", num);
	
		temp = sqrt(num);

		/* find the first factor */
		if (num < 0) {
			printf(" %d", -1);
			num *= -1;
		}
		else if (num != 1) {
			for (i = 0; i < num_primes && primes[i] <= temp; i++) {
				if (num % primes[i] == 0) {
					num /= primes[i];
					printf(" %d", primes[i]);
					break;
				}
			}

			if (i == num_primes || primes[i] > temp) {
				printf(" %d\n", num);
				continue;
			}
		}

		/* find rest factors */	
		i = 0;
		while (num > 1 && i < num_primes) {
			if (num >= primes[i] && num % primes[i] == 0) {
				num /= primes[i];
				printf(" x %d", primes[i]);
			}
			else 
				i++;
		}
		
		if (num != 1 && i == num_primes) {
			printf(" x %d", num);
		}

		printf("\n");
	}	

	return 0;
}
/* @END_OF_SOURCE_CODE */
