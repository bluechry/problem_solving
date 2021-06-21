/* @JUDGE_ID: andrea 10346 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int n, k, b;
	int total;

	while (scanf("%d %d\n", &n, &k) != EOF) {

		total = 0; 
		b = 0;
		while (n > 0) {
			total += n;
			b += n;
			n = b / k;
			b = b % k; 
		}

		printf("%d\n", total);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
