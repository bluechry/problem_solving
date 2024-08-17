/* @JUDGE_ID: andrea 10783 C "Arithmatic" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int num_cases;
	int a, b;
	int n, m;
	int i;

	scanf("%d\n", &num_cases);
	for (i = 1; i <= num_cases; i++) {
		scanf("%d\n", &a);
		scanf("%d\n", &b);

		a = (a & 0x1) ? a : a + 1;
		b = (b & 0x1) ? b : b - 1;
		
		if (a <= b) {
			n = a / 2;
			m = b / 2;
	
			printf("Case %d: %d\n", i, (m + n + 1) * (m - n + 1));
		}
		else {
			printf("Case %d: %d\n", i, 0);
		}	
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
