/* @JUDGE_ID: andrea xxx C++ "Simlulation" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <cstdio>
#include <cmath>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>
#define ABS(x)		((x) < 0 ? -1 * (x) : (x))

using namespace std;


/*@
 * Definitions of External Functions 
 */
void find_primes(int , int[] , int* );
void find_prime_factors(int , int[] , int , int[], int* );
int  check_prime(int );
int  check_prime_fast(int, int[], int );


/*@
 * Implementations of External Functions 
 */
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

int check_prime_fast(int num, int primes[], int num_primes)
{
	int temp, i;

	if (num < 2) 
		return 0;

	temp = sqrt(num);
	for (i = 0; i < num_primes && primes[i] <= temp; i++) {
		if (num == 0) {
			break;
		}

		if (num % primes[i] == 0) {
			return 0; 
		}
	}
	
    return 1;
}


int main()
{
	int primes[5192], num_primes;
	int num;

	find_primes(sqrt(1U << 31), primes, &num_primes); 

	while (scanf("%d\n", &num) != EOF && num != 0) {

		if (check_prime_fast(num, primes, num_primes) == 0) {
			printf("Given number is NOT prime! NO perfect number is available.\n");	
		}
		else if (check_prime_fast((1 << num) - 1, primes, num_primes) == 0) {
			printf("Given number is prime. But, NO perfect number is available.\n");
		}
		else {
			unsigned long long result = (1LLU << (num - 1)) * ((1LLU << num) - 1);
			printf("Perfect: %llu!\n", result); 
		}
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
