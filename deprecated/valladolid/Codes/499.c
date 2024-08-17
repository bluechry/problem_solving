/* @JUDGE_ID: andrea 499 C "Ad Hoc" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <string.h>

int main()
{
	char alphabet[256];
	char ch;
	int  max, i;

	memset(&alphabet[0], 0x0, sizeof(char) * 256);
	while ((ch = getchar()) != EOF) {

		if (ch == '\n') {

			max = 0;
			for (i = 0; i < 256; i++) {
				if (isalpha(i) && alphabet[i] > max) {
					max = alphabet[i];
				}
			}

			for (i = 0; i < 256; i++) {
				if (isalpha(i) && alphabet[i] == max) {
					putchar(i);
				}
			}
			printf(" %d\n", max);

			memset(&alphabet[0], 0x0, sizeof(char) * 256);
		}
		else if (isalpha(ch)) {
			alphabet[ch]++;
		}
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
