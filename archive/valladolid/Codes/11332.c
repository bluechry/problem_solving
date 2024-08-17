/* @JUDGE_ID: andrea 11332 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

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
	int n;
	
	while (scanf("%d\n", &n) != EOF && n != 0) {
		
		while ((n = sum_digits(n)) >= 10) {
			;
		}

		printf("%d\n", n);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
