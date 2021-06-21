/* @JUDGE_ID: andrea 10013 C "Brute force" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int 	num_cases, num_digits;
	int 	op1, op2;
	char 	sum[1000000];
	int 	i, j;

	scanf("%d\n", &num_cases);
	for (i = 0; i < num_cases; i++) {

		if (i > 0) {
			printf("\n");
		}

		scanf("%d\n", &num_digits);
		for (j = 0; j < num_digits; j++) {
			scanf("%d %d\n", &op1, &op2);
			sum[j] = op1 + op2;
		}

		for (j = num_digits - 1; j >= 0; j--) {
			if (sum[j] >= 10) {
				sum[j] -= 10;
				sum[j - 1]++;
			}
		}
		
		for (j = 0; j < num_digits; j++) {
			printf("%d", sum[j]);
		}
		printf("\n");
	}	
	
	return 0;
}
/* @END_OF_SOURCE_CODE */
