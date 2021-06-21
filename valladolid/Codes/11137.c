/* @JUDGE_ID: andrea 11137 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

#define N_COIN 21

int 				coin[N_COIN];
unsigned long long 	num_way[10000];

int main()
{
	int money;
	int i, j;

	/* initialize coins */
	for (i = 0; i < N_COIN; i++) {
		coin[i] = (i + 1) * (i + 1) * (i + 1);
	}

	/* pre-calculation of # of way to pay */
	num_way[0] = 1LLU;
	for (i = 0; i < N_COIN; i++) {
		for (j = coin[i]; j < 10000; j++) {
			num_way[j] += num_way[j - coin[i]];	
		}
	}

	/* input money and output # of way to pay */
	while (scanf("%d\n", &money) != EOF) {
		printf("%llu\n", num_way[money]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
