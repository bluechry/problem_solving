/* @JUDGE_ID: andrea 11185 C "Arithmatic" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int  num;
	char ternary[128];
	int  count;

	while (scanf("%d\n", &num) != EOF && num >= 0) {
		
		if (num == 0) {
			puts("0");
			continue;
		}

		count = 0;	
		while (num > 0) {
			ternary[count++] = num % 3 + '0';
			num /= 3;	
		}	

		while (count > 0) {
			putchar(ternary[--count]);
		}
		printf("\n");
	}	

	return 0;
}
/* @END_OF_SOURCE_CODE */
