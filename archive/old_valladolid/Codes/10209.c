/* @JUDGE_ID: andrea 10209 C "Simple Math" */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <math.h>

#define	PI 3.14159265358979

int main()
{
	double	a;	
	double 	x, y, z;

	while (scanf("%lf", &a) == 1) {
		if (a < 0) {
			break;
		}

		x = a * a * (1 - sqrt(3) + PI / 3);
		y = a * a * (PI / 12 + sqrt(3) / 2 - 1);
		z = a * a * (1 - PI / 6 - sqrt(3) / 4);

		printf("%.3f %.3f %.3f\n", x, 4 * y, 4 * z);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
