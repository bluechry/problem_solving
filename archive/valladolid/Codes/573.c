/* @JUDGE_ID: andrea 573 C "Simulation" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	double 	H, U, D, F;
	double  up_dist, distance;
	int 	days;

	while (scanf("%lf %lf %lf %lf\n", &H, &U, &D, &F) != EOF && H != 0) {

		days = distance = 0;
		while (1) {
			up_dist = (U - days * U * F / 100);
			distance = (up_dist >= 0) ? distance + up_dist: distance;
			++days;
			if (distance > H) break;
			distance -= D;
			if (distance < 0) break;
		}

		if (distance < 0) {
			printf("failure on day %d\n", days);
		}
		else {
			printf("success on day %d\n", days);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
