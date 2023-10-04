/* @JUDGE_ID: andrea 834 C++ "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>
#define ABS(x)		((x) < 0 ? (-1 * (x)) : (x))

using namespace std;

int main()
{
	int			nume, denom, quot, rest;
	vector<int> frac;

	frac.reserve(512);

	while (scanf("%d %d\n", &nume, &denom) != EOF) {

		rest = 0;
		while (ABS(rest) != 1 && rest != -1) {	
			quot = nume / denom;
			rest = nume - quot * denom;

			frac.push_back(quot);

			nume = denom;
			denom = rest;
		}
		frac.push_back(nume);			

		printf("[%d;", frac[0]);
		int i;
		for (i = 1; i < frac.size() - 1; i++) {
			printf("%d,", frac[i]);
		}
		printf("%d]\n", frac[i]);

		frac.clear();
	}

	return 0;	
}

/* @END_OF_SOURCE_CODE */
