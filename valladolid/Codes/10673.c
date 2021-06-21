/* @JUDGE_ID: andrea 10673 C "Number Theory" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int T;
	long long x, k;
	long long p, q;

	scanf("%d\n", &T);
	while (T-- > 0) {
		scanf("%lld %lld\n", &x, &k);

		q = x % k;
		p = k - q;

		printf("%lld %lld\n", p, q);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
