#include <stdio.h>
#include <string.h>
#include <math.h>

/*@
 * Definitions of External Functions 
 */
int  check_prime(int );
void find_primes(int , int[] , int* );
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
	int 	num_cases;
	int 	primes[1024], num_primes;
	char	prime_check_table[2048];
	char	line[2048], *ptr;
	int  	letter_count_table[256], prime_count;
	int 	i, j;

	/* pre-calculate prime numbers */
	find_primes(2000, primes, &num_primes);

	memset(&prime_check_table[0], 0x0, 2048);
	for (i = 0; i < num_primes; i++) {
		prime_check_table[primes[i]] = 1;
	}

	/* receive input and file prime frequency */
	scanf("%d\n", &num_cases);

	for (i = 1; i <= num_cases; i++) {

		memset(&letter_count_table[0], 0x0, sizeof(int) * 255);
		
		gets(&line[0]);

		for (ptr = &line[0]; *ptr != '\0'; ptr++) {
			letter_count_table[*ptr]++;
		}

		printf("Case %d: ", i);
		prime_count = 0;
		for (j = 0; j < 255; j++) {
			if (prime_check_table[letter_count_table[j]]) {
				prime_count++;
				printf("%c", j);
			}
		}
		if (prime_count == 0) {
			printf("empty");
		}
		printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
