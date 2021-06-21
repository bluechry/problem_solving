/* @JUDGE_ID: andrea xxx C++ "Simlulation" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <cstdio>
#include <cctype>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>
#define ABS(x)		((x) < 0 ? -1 * (x) : (x))

using namespace std;

int main()
{
	char ch;
	bool stat;

	stat = false; 
	while ((ch = getchar()) != EOF) {

		char first_ch;

		if (!stat && !isalpha(ch)) {
			putchar(ch);
		}
		else if (!stat && isalpha(ch)) {
			char temp;
			temp = tolower(ch);

			if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u') {
				first_ch = '\0';
				putchar(ch);
			}
			else {
				first_ch = ch;
			}

			stat = true;
		}
		else if (stat && isalpha(ch)) {
			putchar(ch);
		}
		else if (stat && !isalpha(ch)) {
			if (first_ch != '\0') {
				putchar(first_ch);
			}
			printf("ay%c", ch);

			stat = false;
		}
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
