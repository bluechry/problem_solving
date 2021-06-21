/* @JUDGE_ID: andrea 10062 C "Brute Force" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char ch;
	int  freq;
} Entry;

int compare(const void* op1, const void* op2)
{
	Entry* l;
	Entry* r;

	l = (Entry*) op1;
	r = (Entry*) op2;

	if (l->freq == r->freq) {
		return (l->ch - r->ch) * -1;
	}

	return l->freq - r->freq;
}

int main()
{
	char 	line[1024], ch;
	Entry	entry[128];
	int 	i, isFirst;

	isFirst = 1;
	while (gets(line) != NULL) {
		if (isFirst != 1) {
			printf("\n");
		}
		else {
			isFirst = 0;
		}

		/* initialize entry[] */
		memset(&entry[0], 0x0, 128 * sizeof(Entry));

		/* count characters */
		for (i = 0; line[i] != '\0'; i++) {
			ch = line[i];
			
			entry[ch].ch = ch;
			entry[ch].freq++;	
		}

		/* sort entry[] */
		qsort(&entry[0], 128, sizeof(Entry), compare);

		/* print result */
		for (i = 0; i < 128; i++) {
			if (entry[i].freq > 0) {
				printf("%d %d\n", entry[i].ch, entry[i].freq);
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
