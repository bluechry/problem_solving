/* @JUDGE_ID: andrea 10300 C "Arithmatic" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int 		n, f;
	int 		space, degree, animals;
	long long 	premium;

	scanf("%d\n", &n);
	while (n-- > 0) {
		scanf("%d\n", &f);

		premium = 0;
		while (f-- > 0) {
			scanf("%d %d %d\n", &space, &animals, &degree);
			premium += (long long)space * (long long)degree;				
		}

		printf("%lld\n", premium);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
