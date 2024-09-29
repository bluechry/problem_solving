/* @JUDGE_ID: andrea ### C "Geometry" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <math.h>

#define PI	3.14159265358979

int main()
{
	double 	r, n, A;

	while (scanf("%lf %lf\n", &r, &n) != EOF) {
	
		A = sin(2.0 * PI / n) / 2.0 * r * r * n;

		printf("%.3lf\n", A);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
