/* @JUDGE_ID: andrea 10297 C "Geometry" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <math.h>

#define	PI (2.0 * acos(0))

int main()
{
	double	D, V, temp;

	while (scanf("%lf %lf\n", &D, &V) != EOF) {
		
		if (D == 0.0 && V == 0.0) break;
		
		temp = pow(D, 3.0) - (6.0 * V / PI);

		printf("%.3lf\n", pow(temp, 1.0 / 3.0));
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
