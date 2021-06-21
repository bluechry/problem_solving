/* @JUDGE_ID: andrea 10642 C++ "Simlulation" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <cstdio>

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
	int n;

	scanf("%d\n", &n);

	for (int i = 1; i <= n; i++) {

		unsigned long x1, y1, x2, y2;
		unsigned long m1, m2, result;

		scanf("%lu %lu %lu %lu\n", &x1, &y1, &x2, &y2);

		m1 = x1 + y1;
		m2 = x2 + y2;

		result = (m2 * (m2 + 1LU) / 2LU + x2 + 1) - (m1 * (m1 + 1LU) / 2LU + x1 + 1);

		printf("Case %d: %lu\n", i, result);

	}
	

	return 0;		
}

/* @END_OF_SOURCE_CODE */
