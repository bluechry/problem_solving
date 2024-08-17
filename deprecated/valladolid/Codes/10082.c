/* @JUDGE_ID: andrea 10082 C "Simple Search" */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE	1 << 10
#define	N_KEYLINE	4
#define TRUE		1
#define FALSE		0

int main()
{
	const char* key_layout[N_KEYLINE] = {"`1234567890-=", "QWERTYUIOP[]\\", "ASDFGHJKL;'", "ZXCVBNM,./"};
	char		ch;
	int			i;
	char*		pos;
	char		decode_ok;

	while ((ch = getchar()) != EOF) {
		for (decode_ok = FALSE, i = 0; i < N_KEYLINE; i++) {
			pos = strchr(key_layout[i], ch);
			if (pos != NULL) {
				putchar(*--pos);
				decode_ok = TRUE;
				break;
			}
		}
		if (!decode_ok)
			putchar(ch);	
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
