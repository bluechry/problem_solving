/* @JUDGE_ID: andrea 10656 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int N, num;
	int i, count;
	int result[1024];

	while (scanf("%d\n", &N) != EOF && N != 0) {

		count = 0;
		for (i = 0; i < N; i++) {
			scanf("%d\n", &num);
			if (num > 0) {
				result[count++] = num;
			}
		}

		if (count == 0) {
			printf("%d\n", 0);
		}
		else {

			printf("%d", result[0]);
			for (i = 1; i < count; i++) {
				printf(" %d", result[i]);
			}
			printf("\n");
		}
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
