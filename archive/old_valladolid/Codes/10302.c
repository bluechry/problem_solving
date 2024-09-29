/* @JUDGE_ID: andrea 10302 C "Arithmatic" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int num;
	unsigned long long result;

	while (scanf("%d\n", &num) != EOF) {
		
		result = (unsigned long long)num * (num + 1) / 2;
		result = result * result;

		printf("%llu\n", result);
	}


	return 0;
}
/* @END_OF_SOURCE_CODE */
