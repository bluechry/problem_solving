/* @JUDGE_ID: andrea 11172 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int num_cases;
	int l, r;

	scanf("%d\n", &num_cases);
	while (num_cases-- > 0) {
		scanf("%d %d\n", &l, &r);
		if (l == r) puts("=");
		else if (l > r) puts(">");
		else puts("<"); 
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
