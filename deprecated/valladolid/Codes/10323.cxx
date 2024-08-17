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
	int	n;

	while (scanf("%d\n", &n) != EOF) {

		if (n >= 0 && n <= 7) {
			puts("Underflow!");
		}
		else if (n >= 14) {
			puts("Overflow!");
		}
		else if (n < 0 && (n & 0x1)) {
			puts("Overflow!");
		}
		else if (n < 0 && !(n & 0x1)) {
			puts("Underflow!");
		}
		else {
			unsigned long long f;
			for (f = 1LLU; n > 1; n--) {
				f *= n;
			}
			printf("%llu\n", f);
		}
	}
	
	return 0;		
}

/* @END_OF_SOURCE_CODE */
