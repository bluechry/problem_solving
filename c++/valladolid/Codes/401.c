/* @JUDGE_ID: andrea 401 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <string.h>

int main()
{
	char mirror[256];
	char input[32];
	int  count, length;
	int  i, j; 
	int  is_mirror, is_palindrome;

	/* Init a mirror */
	mirror['A'] = 'A';
	mirror['B'] = '\0';
	mirror['C'] = '\0';
	mirror['D'] = '\0';
	mirror['E'] = '3';
	mirror['F'] = '\0';
	mirror['G'] = '\0';
	mirror['H'] = 'H';
	mirror['I'] = 'I';
	mirror['J'] = 'L';
	mirror['K'] = '\0';
	mirror['L'] = 'J';
	mirror['M'] = 'M';
	mirror['N'] = '\0';
	mirror['O'] = 'O';
	mirror['P'] = '\0';
	mirror['Q'] = '\0';
	mirror['R'] = '\0';
	mirror['S'] = '2';
	mirror['T'] = 'T';
	mirror['U'] = 'U';
	mirror['V'] = 'V';
	mirror['W'] = 'W';
	mirror['X'] = 'X';
	mirror['Y'] = 'Y';
	mirror['Z'] = '5';
	mirror['1'] = '1';
	mirror['2'] = 'S';
	mirror['3'] = 'E';
	mirror['4'] = '\0';
	mirror['5'] = 'Z';
	mirror['6'] = '\0';
	mirror['7'] = '\0';
	mirror['8'] = '8';
	mirror['9'] = '\0';

	while (gets(input) != NULL) {
		/* Check Palindrome and mirror string */
		length = strlen(input);
		is_mirror = is_palindrome = 1;
		for (i = 0, j = length - 1; i <= j; i++, j--) {
			if (input[i] != input[j]) 
				is_palindrome = 0;
			if (mirror[input[i]] != input[j]) 
				is_mirror = 0;

			if (is_palindrome == 0 && is_mirror == 0) 
				break;
		}

		/* Print result */
		if (is_mirror == 1 && is_palindrome == 1) {
			printf("%s -- is a mirrored palindrome.\n", input);
		}
		else if (is_mirror == 1 && is_palindrome == 0) {
			printf("%s -- is a mirrored string.\n", input);
		}
		else if (is_mirror == 0 && is_palindrome == 1) {
			printf("%s -- is a regular palindrome.\n", input);
		}
		else {
			printf("%s -- is not a palindrome.\n", input);
		}
		
		printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
