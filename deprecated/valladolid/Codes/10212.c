/* @JUDGE_ID: andrea 10212 C "Number Theory" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{

	unsigned long 		n, m;
	unsigned long 		i;
	unsigned long long 	mult;

	while (scanf("%lu %lu\n", &n, &m) != EOF) {
		if (m == 0LLU) {
			printf("%d\n", 1);
			continue;	
		}
	
		mult = 1LLU;	
		for (i = n; i > n - m; i--) {
			mult *= i;
			while (mult % 10 == 0) {
				mult /= 10;
			}
			mult %= 1000000000;
		}

		printf("%d\n", mult % 10);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
