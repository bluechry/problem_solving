/* @JUDGE_ID: andrea 10055 C "Ad Hoc" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	unsigned long long i, j, result;
	
	while (scanf("%llu %llu\n", &i, &j) != EOF) {
		result = (i > j) ? i - j : j - i;
		printf("%llu\n", result);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
