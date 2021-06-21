/* @JUDGE_ID: andrea 10347 C++ "Geometry" */
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

using namespace std;

int main()
{
	double	a, b, c;
	double 	S, A;

	while (cin >> a >> b >> c) {

		S = 0.5 * (a + b + c);
		A = S * (S - a) * (S - b) * (S - c);
		if (A <= 0) {
			printf("-1.000\n");
		}
		else {
			A = sqrt(A) * 4.0 / 3.0;
			printf("%0.3lf\n", A);
		}	
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
