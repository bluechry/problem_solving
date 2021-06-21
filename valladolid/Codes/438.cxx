/* @JUDGE_ID: andrea 438 C++ "Geometry" */
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

#define PI	3.141592653589793

using namespace std;

inline double get_length(double x1, double y1, double x2, double y2)
{
	double result;

	result = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

	return result;
}

int main()
{
	double x1, y1, x2, y2, x3, y3;

	while (scanf("%lf %lf %lf %lf %lf %lf\n", &x1, &y1, &x2, &y2, &x3, &y3) != EOF) {
		
		double a = get_length(x2, y2, x3, y3);
		double b = get_length(x1, y1, x3, y3);
		double c = get_length(x1, y1, x2, y2);

		double s = (a + b + c) / 2;
		double S = sqrt(s * (s - a) * (s - b) * (s - c));

		double cir = (a * b * c * PI) / (2 * S); 

		printf("%.2lf\n", cir);
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
