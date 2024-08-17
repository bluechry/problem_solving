/* @JUDGE_ID: andrea 10451 C++ "Simlulation" */
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
	double n, A;
	double outer, inner;
	double pi;
	int	   count;

	pi = 2 * acos(0);

	count = 1;
	while (scanf("%lf %lf\n", &n, &A) != EOF && n > 2.0) {

		outer = (pi * 2 * A) / (n * sin(2 * pi / n));
		inner = (A * pi) / (n * tan(pi / n));

		printf("Case %d: %.5lf %.5lf\n", count++, outer - A, A - inner);	

	}


	return 0;		
}

/* @END_OF_SOURCE_CODE */
