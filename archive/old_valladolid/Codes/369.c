/* @JUDGE_ID: andrea 369 C "Dynamic Programming" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

#define MAX_NUM	100

int main()
{
	int  n, k;
	long comb_table[MAX_NUM + 1][MAX_NUM + 1];

	for (n = 0; n <= MAX_NUM; n++) {
		for (k = 0; k <= n; k++) {
			if (n == k || k == 0) {
				comb_table[n][k] = 1;
			}
			else {
				comb_table[n][k] = comb_table[n - 1][n - k] + comb_table[n - 1][k];
			}
		}
	}

	while (scanf("%d %d\n", &n, &k) != EOF) {
		if (n == 0 && k == 0) {
			break;	
		}
	
		printf("%d things taken %d at a time is %ld exactly.\n", n, k, comb_table[n][k]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
