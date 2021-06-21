
#include <stdio.h>
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
	int 	num, base, exp;
	int 	primes[1 << 12], num_primes;
	int 	factors[1 << 12], num_factors;
	int		prev, result;
	int 	i;


	/* Pre-calculate the prime numbers */	
	find_primes(sqrt(1000000000), primes, &num_primes);


	/* Finding # of relatively primes using the Euler's phi function */
	while (scanf("%d\n", &num) != EOF && num != 0) {

		if (num == 1) {
			printf("%d\n", 0);
			continue;
		}
		
		find_prime_factors(num, primes, num_primes, factors, &num_factors);

		prev = 0;
		result = num;
		for (i = 0; i < num_factors; i++) {
			
			if (factors[i] == prev) {
				continue;
			}
			else {
				prev = factors[i];
				result = result - result / prev;
			}
				
		}

		printf("%d\n", result);
	}		

	return 0;
}

