/* @JUDGE_ID: andrea 445 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	char 	ch;
	int		repeat;

	repeat = 0;
	while ((ch = getchar()) != EOF) {

		if (ch >= '1' && ch <= '9') {
			repeat += (ch - '0');
		}
		else if (ch == 'b') {
			for ( ; repeat > 0; repeat--) {
				putchar(' ');
			}
		}
		else if (ch >= 'A' && ch <= 'Z' || ch == '*') {
			for ( ; repeat > 0; repeat--) {
				putchar(ch);
			}
		}
		else if (ch == '!' || ch == '\n') {
			putchar('\n');
		}
	}	

	return 0;		
}

/* @END_OF_SOURCE_CODE */
