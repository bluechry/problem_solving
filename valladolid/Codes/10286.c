/* @JUDGE_ID: andrea 10286 C "Mathematics" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <math.h>

#define PI	(2.0 * acos(0))

int main()
{
	double coeff;
	double F, result;

	coeff = sin(108.0 / 180.0 * PI) / sin(63.0 / 180.0 * PI);

	while (scanf("%lf\n", &F) != EOF) {
		
		result = coeff * F;

		printf("%.10lf\n", result);	
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
