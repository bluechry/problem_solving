/* @JUDGE_ID: andrea 10195 C++ "Simlulation" */
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
	double a, b, c;
	double s, r;

	while (scanf("%lf %lf %lf\n", &a, &b, &c) != EOF) {

		if (a == 0 || b == 0 || c == 0) {
			printf("The radius of the round table is: 0.000\n");
			continue;
		}

		s = (a + b + c) / 2;
		r = sqrt((s - a) * (s - b) * (s - c) / s);

		printf("The radius of the round table is: %.3lf\n", r);
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
