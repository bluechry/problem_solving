/* @JUDGE_ID: andrea 636 C "Arithmatic" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <math.h>

int main()
{
	char num[1024], *ptr;
	int  dec_num, max, i;
	
	while (gets(num) != NULL && num[0] != '0') {
		/* find maximum digit */
		for (max = 0, ptr = &num[0]; *ptr != '\0'; ptr++) {
			if (max < (*ptr - '0')) {
				max = *ptr - '0';
			}
		}
	
		/* find minimum base */	
		for (i = max + 1; i < 100; i++) {
			for (dec_num = 0, ptr = &num[0]; *ptr != '\0'; ptr++) {
				dec_num = dec_num * i + (*ptr - '0'); 
			}
			if (pow((int)sqrt(dec_num), 2) == dec_num) {
				break;
			}
		}
		printf("%d\n", i);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
