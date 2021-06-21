/* @JUDGE_ID: andrea 10633 C "Brute force" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	long long 	N, K;
	long long 	r, a;
	long long 	result[1024];
	int			count, i;


	while (scanf("%lld\n", &K) != EOF && K != 0) {

		count = 0;
		for (r = 9LL; r >= 0LL; --r) {

			if ((K - r) % 9LL) {
				continue;
			}

			a = (K - r) / 9LL;
			N = 10LL * a + r;

			result[count++] = N;	
		}

		printf("%lld", result[0]);
		for (i = 1; i < count; i++) {
			printf(" %lld", result[i]);
		}

		printf("\n");
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
