/* @JUDGE_ID: andrea 900 C "Number Theory" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int num_brick_wall[64];
	int i;

	num_brick_wall[1] = 1;
	num_brick_wall[2] = 2;

	for (i = 3; i < 64; i++) {
		num_brick_wall[i] = num_brick_wall[i - 1] + num_brick_wall[i - 2];
	}

	while (scanf("%d\n", &i) != EOF && i != 0) {
		printf("%d\n", num_brick_wall[i]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
