/* @JUDGE_ID: andrea 10071 C "Simple Arithmetic" */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>

int main()
{
	register int v, t;
	
	while (scanf("%d %d", &v, &t) == 2) {
		printf("%d\n", 2 * v * t);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
