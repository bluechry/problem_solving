/* @JUDGE_ID: andrea 10469 C "arithmatic" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	unsigned int op1, op2;

	while (scanf("%u %u\n", &op1, &op2) != EOF) {
		printf("%u\n", op1 ^ op2);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
