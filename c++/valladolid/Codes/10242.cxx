/* @JUDGE_ID: andrea 10242 C++ "Simlulation" */
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

typedef struct {
	double x, y;
} Point;

inline void find_fourth_point(Point& p1, Point& p2, Point& p3, Point& result)
{
	result.x = p2.x + p3.x - p1.x;  
	result.y = p2.y + p3.y - p1.y; 
}

inline bool equal(Point& p1, Point& p2)
{
	return (p1.x == p2.x && p1.y == p2.y);
}

int main()
{
	Point 	p1, p2, p3, p4;
	Point	result;

	while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf\n", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y, &p4.x, &p4.y) != EOF) {
		
		if (equal(p1, p3)) {
			find_fourth_point(p1, p2, p4, result);
		}
		else if (equal(p1, p4)) {
			find_fourth_point(p1, p2, p3, result);
		}
		else if (equal(p2, p3)) {
			find_fourth_point(p2, p1, p4, result);
		}
		else if (equal(p2, p4)) {
			find_fourth_point(p2, p1, p3, result);
		}

		printf("%0.3lf %0.3lf\n", result.x, result.y);
	}
	
	return 0;		
}

/* @END_OF_SOURCE_CODE */
