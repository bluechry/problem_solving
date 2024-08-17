/* @JUDGE_ID: andrea 10222 C "Ad Hoc." */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	char* 	keyboard[4] = {"`1234567890-=", "qwertyuiop[]\\", "asdfghjkl;'", "zxcvbnm,./"};
	char	ch, found;
	int 	i, j;


	while (scanf("%c", &ch) != EOF) {
	
		/* Convert an upper case to an lower case */
		if (ch >= 'A' && ch <= 'Z') {
			ch = ch - 'A' + 'a';
		}

		/* Find the location of the given character */
		found = 0;
		for (i = 0; i < 4; i++) {
			for (j = 0; keyboard[i][j] != '\0'; j++) {
				if (keyboard[i][j] == ch) {
					found = 1;
					break;	
				}
			}

			if (found) break;
		}

		if (found)
			putchar(keyboard[i][j - 2]);	
		else 
			putchar(ch);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
