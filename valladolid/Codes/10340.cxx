/* @JUDGE_ID: andrea xxx C++ "Simlulation" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
	char s[100000], t[100000];

	while (scanf("%s %s\n", s, t) != EOF) {

		char* s_ptr = &s[0];
		for (char* t_ptr = &t[0]; *t_ptr != '\0' && *s_ptr != '\0'; t_ptr++) {
			if (*t_ptr == *s_ptr) s_ptr++;	
		}

		if (*s_ptr == '\0') {
			puts("Yes");
		}
		else {
			puts("No");
		}
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
