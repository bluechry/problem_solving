/* @JUDGE_ID: andrea 10042 C "Number Theory" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
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

int sum_digits(int num)
{
	int result;

	result = 0;
	while (num > 0) {
		result += num % 10;
		num /= 10;
	}

	return result;
}

int main()
{
	int primes[5 * 1 << 10], num_primes;
	int factors[5 * 1 << 10], num_factors;
	int num_cases, num;
	int sum_1, sum_2;
	int i;

	
	find_primes(sqrt(pow(10, 9)), primes, &num_primes);	

	scanf("%d\n", &num_cases);
	while (num_cases-- > 0) {
		scanf("%d\n", &num);

		while (num++) {
			find_prime_factors(num, primes, num_primes, factors, &num_factors);

			sum_1 = sum_digits(num);
			for (sum_2 = 0, i = 0; i < num_factors; i++) {
				sum_2 += sum_digits(factors[i]);		
			}

			if (num_factors != 1 && sum_1 == sum_2) {
				printf("%d\n", num);
				break;
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
