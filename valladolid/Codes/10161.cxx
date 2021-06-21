/* @JUDGE_ID: andrea 10161 C++ "Simlulation" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <cstdio>
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
	long	N, cv, gap, i;

	while (scanf("%ld\n", &N) != EOF && N != 0) {

		i   = (long)ceil(sqrt(N));
		cv  = i * i - i + 1;
		gap = ABS(N - cv);

		if (i & 0x1) {
			if (N > cv) {
				printf("%ld %ld\n", i - gap, i);
			}
			else {
				printf("%ld %ld\n", i, i - gap);
			}
		}
		else {
			if (N > cv) {
				printf("%ld %ld\n", i, i - gap);
			}
			else {
				printf("%ld %ld\n", i - gap, i);
			}
		} 	

	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
