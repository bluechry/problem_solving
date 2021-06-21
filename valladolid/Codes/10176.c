/* @JUDGE_ID: andrea 10176 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

#define DENOM 131071

int main()
{
	char ch;
	int  remain;

	while (1) {
		/* receive each digit */
		remain = 0;
		while (scanf("%c", &ch) != EOF && ch != '#') {
			if (ch != '\n') {
				remain = (remain * 2 + ch - '0') % 131071;
			}
		}

		/* end of a binary number */
		if (ch != '#') {
			break;
		}

		if (remain) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	} 

	return 0;
}
/* @END_OF_SOURCE_CODE */
