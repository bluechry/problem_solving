/* @JUDGE_ID: andrea 10696 C "Arithmatic" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int n;

	while (scanf("%d\n", &n) != EOF && n != 0) {
		
		if (n > 100) {
			printf("f91(%d) = %d\n", n, n - 10);
		}
		else {
			printf("f91(%d) = %d\n", n, 91);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
