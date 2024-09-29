/* @JUDGE_ID: andrea 913 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int 				N, n;
	unsigned long long 	sum;

	while (scanf("%d\n", &N) != EOF) {
		n = (N + 1) / 2;
		sum = 6LLU * (unsigned long long)n * (unsigned long long)n - 9LLU;

		printf("%llu\n", sum);
	}	

	return 0;
}
/* @END_OF_SOURCE_CODE */
