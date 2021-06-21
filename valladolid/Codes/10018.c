/* @JUDGE_ID: andrea 10018 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long reverse(unsigned long num)
{
	unsigned long rev;

	rev = 0;
	while (num > 0) {
		rev = rev * 10 + num % 10;
		num /= 10;
	}

	return rev;
}

int main()
{
	int 			nCases;
	unsigned long 	num;
	unsigned long	rev;
	int				count;

	scanf("%d\n", &nCases);

	while (nCases-- > 0) {
		scanf("%lu\n", &num);
		
		count = 0;
		while (num != (rev = reverse(num))) {
			num += rev;
			count++;			
		}

		printf("%d %lu\n", count, num);
	}


	return 0;
}

/* @END_OF_SOURCE_CODE */
