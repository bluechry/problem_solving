/* @JUDGE_ID: andrea 11547 C "Arithmatic" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <math.h>

int main()
{
	int 	num_cases;
	double 	n;
	int		result;

	scanf("%d\n", &num_cases);
	while (num_cases-- > 0) {
		scanf("%lf\n", &n);
		n = (n * 567.0 / 9.0 + 7492.0) * 235.0 / 47.0 - 498.0;
		result = (int)(n + 0.5);
		result = abs(result / 10 % 10);

		printf("%d\n", result);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
