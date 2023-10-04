/* @JUDGE_ID: andrea 10190 C "Simulation" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int a[64];
	int n, m;
	int i;

	while (scanf("%d %d\n", &n, &m) != EOF) {
		
		if (n < 2 || m < 2) {
			puts("Boring!");
			continue;
		}

		a[1] = n;
		i = 1;
		while (1) {
			if ((a[i] == 1) || (a[i] % m != 0)) {
				break;
			}
			a[i + 1] = a[i] / m;
			i++;
		}

		if (a[i] != 1) {
			puts("Boring!");
		}
		else {
			for (i = 1; a[i] != 1; i++) {
				printf("%d ", a[i]);
			}
			printf("1\n");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
