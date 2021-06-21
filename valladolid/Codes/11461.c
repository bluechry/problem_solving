/* @JUDGE_ID: andrea 11461 C "Arithmatic" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <math.h>

int main()
{
	int a, b;
	int root[1 << 17];
	int i, j, temp;

	temp = sqrt(100000);
	for (i = 1; i <= temp; i++) {
		for (j = i * i; j < (i + 1) * (i + 1); j++) {
			root[j] = i;
		}	
	}	

	while (scanf("%d %d\n", &a, &b) != EOF && a != 0 && b != 0) {

		printf("%d\n", root[b] - root[a - 1]);		

	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
