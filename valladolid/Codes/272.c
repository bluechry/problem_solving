/* @JUDGE_ID: andrea 272 C "Bruteforce" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	char ch;
	char flag;

	flag = 0;
	while ((ch = getchar()) != EOF) {

		if (ch == '\"' && flag == 0) {
			printf("``");
			flag ^= 1;
		}
		else if (ch == '\"' && flag == 1) {
			printf("''");
			flag ^= 1;
		}
		else {
			putchar(ch);
		}
	}	

	return 0;
}
/* @END_OF_SOURCE_CODE */
