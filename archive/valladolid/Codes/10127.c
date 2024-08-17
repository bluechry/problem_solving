/* @JUDGE_ID: andrea 10127 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int n;
	int ones, num_digits;

	while (scanf("%d\n", &n) != EOF) {
		
		num_digits = 1;
		ones = 1;
		while (n > ones) {
			ones = ones * 10 + 1;
			num_digits++;
		}

		while (ones % n != 0) {
			ones = (ones % n) * 10 + 1;
			num_digits++;
		}
		
		printf("%d\n", num_digits);	
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
