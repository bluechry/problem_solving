/* @JUDGE_ID: andrea 10050 C "Simulation" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <string.h>

int main()
{
	int  num_cases;
	int  T, N, P, h[128];
	char hartal_table[4092];
	int  i, j, count;

	scanf("%d\n", &num_cases);
	while (num_cases-- > 0) {

		scanf("%d\n", &N);
		scanf("%d\n", &P);
		for (i = 0; i < P; i++) {
			scanf("%d\n", &h[i]);
		}

		memset(hartal_table, 0x0, sizeof(char) * 4092);
	
		for (j = 1; j <= N; j++) {
			if (j % 7 == 6 || j % 7 == 0) continue;

			for (i = 0; i < P; i++) {
				if (j % h[i] == 0) hartal_table[j] = 1;
			}
		}	

		for (count = 0, j = 1; j <= N; j++) {
			if (hartal_table[j] == 1) count++;
		}

		printf("%d\n", count);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
