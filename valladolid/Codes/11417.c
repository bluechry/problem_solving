/* @JUDGE_ID: andrea 11417 C "Number Theory" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int GCD(int n, int d)
{
	int temp;

	while (d > 0) {
		temp = n;
		n = d;
		d = temp % d;	
	}

	return n;
}

int main()
{
	int N, G;
	int i, j;

	while (scanf("%d\n", &N) != EOF && N != 0) {
		G = 0;
		for (i = 1; i < N; i++) {
			for (j = i + 1; j <= N; j++) {
				G += GCD(i, j);
			}
		}

		printf("%d\n", G);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
