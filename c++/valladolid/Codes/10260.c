/* @JUDGE_ID: andrea 10260 C "Ad Hoc" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int	code[26] = {/* A */ 0, /* B */ 1, /* C */ 2, /* D */ 3, /* E */ 0, /* F */ 1,
					/* G */ 2, /* H */ 0, /* I */ 0, /* J */ 2, /* K */ 2, /* L */ 4,
					/* M */ 5, /* N */ 5, /* O */ 0, /* P */ 1, /* Q */ 2, /* R */ 6,
					/* S */ 2, /* T */ 3, /* U */ 0, /* V */ 1, /* W */ 0, /* X */ 2,
					/* Y */ 0, /* Z */ 2};
	char line[32];

	while (gets(line) != NULL) {
		char* ptr;
		int	  codeVal, prevCodeVal;

		prevCodeVal = -1;
		for (ptr = &line[0]; *ptr != '\0'; ptr++) {
			if ((codeVal = code[*ptr - 'A']) != 0 && codeVal != prevCodeVal) {
				printf("%d", code[*ptr - 'A']);
			}
			prevCodeVal = codeVal;
		}
		printf("\n");	
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
