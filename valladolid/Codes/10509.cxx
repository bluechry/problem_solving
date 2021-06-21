/* @JUDGE_ID: andrea 10509 C++ "Simlulation" */
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
	double cubic_num[1024];

	for (int i = 1; i <= 101; i++) {
		cubic_num[i] = (double) (i * i * i);
	}

	double num;
	while (scanf("%lf\n", &num) != EOF && num != 0.0) {

		double a, dx;
		for (int i = 1; i <= 101; i++) {
			if (num < cubic_num[i]) {
				a = (double) (i - 1);
				break;
			}
		}

		dx = (num - a * a * a) / (3.0 * a * a);

		printf("%.4lf\n", a + dx);
	}

	return 0;		
}
/* @END_OF_SOURCE_CODE */
