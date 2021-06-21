/* @JUDGE_ID: andrea 113 C "Arithmatic & Algebra" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <math.h>

int main()
{
	double 	p, n, k;

	while (scanf("%lf %lf", &n, &p) == 2) {
		k = pow(10, log10(p) / n);

		printf("%.0lf\n", k);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
