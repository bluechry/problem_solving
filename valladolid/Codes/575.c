/* @JUDGE_ID: andrea 575 C "Arithmatics" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	char 	skew[1024], *ptr;
	int 	count, dec, len;

	while (gets(skew) != NULL && skew[0] != '0') {
		ptr = &skew[strlen(skew) - 1];
		dec = count = 0;
		while (ptr >= &skew[0]) {
			count++;
			dec = dec + (*ptr - '0') * (pow(2, count) - 1);
			ptr--;
		}	
		printf("%d\n", dec);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
