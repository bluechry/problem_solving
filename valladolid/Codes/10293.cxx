/* @JUDGE_ID: andrea 10293 C++ "Simlulation" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>

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
	int	 freq_length[32];

	// init frequencies of word length
	memset(&freq_length[0], 0x0, sizeof(int) * 32);

	// read characters and count length of a word
	bool is_word = false;
	char ch, prev_ch = '\n';
	int  word_len = 0;

	while (1) {
		if (is_word) {	// is word

			char ch;
			if ((ch = getchar()) == EOF) {
				break;
			}

			if (isspace(ch) || ch == '?' || ch == '!' || ch == ',' || ch == '.') {

				if (ch == '\n' && prev_ch == '-') {
					prev_ch = ch;
					continue;
				}

				freq_length[word_len]++;
				word_len = 0;
				prev_ch = ch;
				is_word = false;
			}
			else {
				if (ch == '\'' || ch == '-') {
					prev_ch = ch;
					continue;
				}

				word_len++;
				prev_ch = ch;				
			}
		}
		else {			// is not word

			char ch;
			if ((ch = getchar()) == EOF) {
				break;
			}

			if (prev_ch == '\n' && ch == '#') {

				for (int i = 0; i < 32; i++) {
					if (freq_length[i] > 0) {
						printf("%d %d\n", i, freq_length[i]);
					}
				}
				printf("\n");

				memset(&freq_length[0], 0x0, sizeof(int) * 32);
				prev_ch = ch;
			}
			else if (isspace(ch) || ch == '?' || ch == '!' || ch == ',' || ch == '.') {
				prev_ch = ch;
				continue;
			}
			else {
				if (ch == '\'' || ch == '-') {
					prev_ch = ch;
					continue;
				}

				word_len++;
				prev_ch = ch;	
				is_word = true;
			}
		}
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
