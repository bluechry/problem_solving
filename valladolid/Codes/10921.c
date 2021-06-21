/* @JUDGE_ID: andrea 10921 C "Ad Hoc" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int 	hash_table[128];
	char 	line[32];

	hash_table['A'] = '2';
	hash_table['B'] = '2';
	hash_table['C'] = '2';

	hash_table['D'] = '3';
	hash_table['E'] = '3';
	hash_table['F'] = '3';
	
	hash_table['G'] = '4';
	hash_table['H'] = '4';
	hash_table['I'] = '4';

	hash_table['J'] = '5';
	hash_table['K'] = '5';
	hash_table['L'] = '5';

	hash_table['M'] = '6';
	hash_table['N'] = '6';
	hash_table['O'] = '6';

	hash_table['P'] = '7';
	hash_table['Q'] = '7';
	hash_table['R'] = '7';
	hash_table['S'] = '7';

	hash_table['T'] = '8';
	hash_table['U'] = '8';
	hash_table['V'] = '8';

	hash_table['W'] = '9';
	hash_table['X'] = '9';
	hash_table['Y'] = '9';
	hash_table['Z'] = '9';

	while (gets(line) != NULL) {
		char* ptr;

		for (ptr = &line[0]; *ptr != '\0'; ptr++) {
			if (*ptr >= 'A' && *ptr <= 'Z') {
				printf("%c", hash_table[*ptr]);
			}
			else {
				printf("%c", *ptr);
			}
		}
		printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
