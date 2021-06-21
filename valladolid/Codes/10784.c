/* @JUDGE_ID: andrea 10784 C "Mathematics" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <math.h>

int main()
{
	unsigned long long	N, n;
	int 				count;

	count = 0;
	while (scanf("%llu\n", &N) && N != 0) {

		n = ceil((3.0 + sqrt(9.0 + 8.0 * N)) / 2.0);	

		printf("Case %d: %llu\n", ++count, n); 
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
