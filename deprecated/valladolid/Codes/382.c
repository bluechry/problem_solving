/* @JUDGE_ID: andrea 382 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <math.h>

int add_divisors(int num)
{
	int temp, i;
	unsigned int sum;

	temp = sqrt(num);
	sum = 1;
	for (i = 2; i <= temp; i++) {
		sum = (num % i) ? sum : (sum + i + (num / i));
	}

	sum = (temp * temp == num) ? (sum - temp) : sum;

	return sum;
}

int main()
{
	int num, sum;

	puts("PERFECTION OUTPUT");
	while (scanf("%d", &num) != EOF && num != 0) {
		sum = add_divisors(num);
		
		if (sum == num) {
			printf("%5u  PERFECT\n", num);
		}
		else if (sum < num) {
			printf("%5u  DEFICIENT\n", num);
		}
		else {
			printf("%5u  ABUNDANT\n", num);
		}	
	}
	puts("END OF OUTPUT");

	return 0;
}
/* @END_OF_SOURCE_CODE */
