/* @JUDGE_ID: andrea 494 C "Ad Hoc" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int 	isWord;
	int 	count;
	char 	ch;
	
	isWord = 0;
	count  = 0;	
	while ((ch = getchar()) != EOF) {

		if (isWord == 0 && isalpha(ch)) {
			isWord = 1;
			count++;
		}
		else if (isWord == 1 && !isalpha(ch)) {
			isWord = 0;
		}

		if (ch == '\n') {
			printf("%d\n", count);
			count = 0;
		}
	}	

	return 0;		
}

/* @END_OF_SOURCE_CODE */
