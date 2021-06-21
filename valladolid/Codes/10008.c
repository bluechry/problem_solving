/* @JUDGE_ID: andrea 10008 C "Brute Force" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char ch;
	int	 count;
} Entry;

int compare(const void* op1, const void* op2)
{
	Entry* l;
	Entry* r;

	l = (Entry*) op1;
	r = (Entry*) op2;

	if (l->count == r->count) {
		return l->ch - r->ch;
	}
	
	return r->count - l->count;
}

int main()
{
	Entry 	char_table[32];
	char	line[1024], *ptr;
	int		num_cases, i;


	memset(&char_table[0], 0x0, sizeof(Entry) * 32);
	
	scanf("%d\n", &num_cases);
	while (num_cases-- > 0) {
	
		gets(line);

		for (ptr = &line[0]; *ptr != '\0'; ptr++) {

			if (*ptr >= 'A' && *ptr <= 'Z') {
				char_table[*ptr - 'A'].ch = *ptr;
				char_table[*ptr - 'A'].count++;
			}
			else if (*ptr >= 'a' && *ptr <= 'z') {
				char_table[*ptr - 'a'].ch = *ptr - 'a' + 'A';
				char_table[*ptr - 'a'].count++;
			}
		}	
	}	

	qsort(&char_table[0], 32, sizeof(Entry), compare);

	for (i = 0; i < 32; i++) {
		if (char_table[i].count > 0) {
			printf("%c %d\n", char_table[i].ch, char_table[i].count);
		}
	}
	
	return 0;
}
/* @END_OF_SOURCE_CODE */
