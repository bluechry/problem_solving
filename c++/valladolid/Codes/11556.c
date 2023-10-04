/* @JUDGE_ID: andrea 11556 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{

	unsigned long long 	N, temp;
	int				 	b;

	while (scanf("%llu %d\n", &N, &b) != EOF) {
		temp = (1LLU << ++b) - 1;	
		if (temp >= N) {
			puts("yes");
		}
		else {
			puts("no");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
