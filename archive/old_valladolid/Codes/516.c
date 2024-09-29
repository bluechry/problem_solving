/* @JUDGE_ID: andrea 516 C "Number Theory" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <string.h>
#include <math.h>


/*@
 * Definitions of External Functions 
 */
int  check_prime(int );
void find_prime(int , int[] , int* );
void find_prime_factors(int , int[] , int , int[], int* );


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

void find_prime_factors(int num, int primes[], int num_primes, int factors[], int* num_factors)
{
	int temp, count;
	int i;

	temp = sqrt(num);
	count = 0;

	for (i = 0; i < num_primes && primes[i] <= temp; ) {
		if (num == 0) {
			break;
		}

		if (num % primes[i] == 0) {
			num /= primes[i];
			factors[count++] = primes[i];
		}
		else {
			i++; 
		}
	}
	
	if (num > 1) {
		factors[count++] = num;
	}

	*num_factors = count;

	return;
}

int main()
{
	int 	num, base, exp;
	int 	primes[1 << 10], num_primes;
	int 	factors[1 << 10], num_factors;
	char 	line[4096];
	int 	i, count, prev;


	/* Pre-calculate prime numbers */
	find_primes(sqrt(32767), primes, &num_primes);
	/* find_primes(32767, primes, &num_primes); */

	/* Process input */
	while (gets(line) != NULL && line[0] != '0') {

		/* Tokenize the given string and make an integer number */
		char* tok;
		char* ptr = &line[0];
		num = 1;
		while ((tok = strtok(ptr, " ")) != NULL) {
			base = strtol(tok, NULL, 10);

			tok = strtok(NULL, " ");
			exp = strtol(tok, NULL, 10);

			num *= pow(base, exp);

			ptr = NULL;	
		}
		--num;

		/* Prime-factorization of the integer number */
		find_prime_factors(num, primes, num_primes, factors, &num_factors);
		
		/* Outout prime factors */
		prev = factors[num_factors - 1];
		count = 1;
		printf("%d", prev);
		for (i = num_factors - 2; i >= 0; i--) {
			if (factors[i] == prev) {
				count++;
			} 
			else {
				printf(" %d", count);
				prev = factors[i];
				printf(" %d", prev);
				count = 1;
			}
		}
		printf(" %d", count);
		printf("\n");
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */
