/* @JUDGE_ID: andrea 458 C "Ad Hoc" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	char ch;

	while ((ch = getchar()) != EOF) {
		if (ch != '\n') {
			ch -= 7;
		}
		putchar(ch);
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
