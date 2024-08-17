/* @JUDGE_ID: andrea 11000 C "Simulation" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

#define MAX 1LL << 32	

int main()
{
	long long num_male[128];
	long long num_female[128];
	int 	  year;
	int 	  i;

	num_male[0]   = 0;
	num_female[0] = 1;
	num_male[1]   = 1;
	num_female[1] = 1;

	for (i = 2; ; i++) {
		num_male[i] = num_male[i - 1] + num_female[i - 1];
		num_female[i] = num_male[i - 1] + 1;

		if (num_female[i] > MAX || num_male[i] > MAX) {
			break;
		}
	}

	while (scanf("%d\n", &year) != EOF && year != -1) {
		
		printf("%lld %lld\n", num_male[year], num_male[year] + num_female[year]);	

	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
