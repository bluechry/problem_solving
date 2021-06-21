/* @JUDGE_ID: andrea 11044 C "Arithmatic" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int num_cases;
	int n, m;

	scanf("%d\n", &num_cases);
	while (num_cases-- > 0) {
		scanf("%d %d\n", &n, &m);
		
		printf("%d\n", (n / 3) * (m / 3));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
