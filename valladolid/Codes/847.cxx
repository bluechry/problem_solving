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
	unsigned long n;

	while (scanf("%lu\n", &n) != EOF) {

		int turn = 0x0;
		while (n > 1) {
			n = (n - 1) / (turn ? 2 : 9) + 1;
			turn ^= 0x1; 
		}
	
		printf("%s wins.\n", (turn ? "Stan" : "Ollie"));	
	}	
	
	return 0;		
}

/* @END_OF_SOURCE_CODE */
