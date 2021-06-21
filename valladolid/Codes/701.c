/* @JUDGE_ID: andrea 701 C "arithmetic" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <math.h>
#include <limits.h>

int main()
{
	unsigned long 	n;
	double 			lower, upper;
	int				num_digits, i;
	int				found, E;


	while (scanf("%lu\n", &n) != EOF) {
		num_digits = floor(log10(n)) + 1;

		found = 0;
		for (i = num_digits + 1; i <= INT_MAX; i++) {
			upper = (log10(n + 1) + i) / log10(2);
			lower = (log10(n) + i) / log10(2);

			if ((E = ceil(lower)) <= upper) {
				found = 1;	
				break;
			} 
		}
	
		if (found) {
			printf("%d\n", E);
		}
		else {
			printf("no power of 2\n");
		}
	}


	return 0;
}
/* @END_OF_SOURCE_CODE */
