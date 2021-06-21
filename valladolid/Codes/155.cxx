/* @JUDGE_ID: andrea 155 C++ "Geometry" */
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

using namespace std;

inline void trans_point(int x_mid, int y_mid, int* x, int* y)
{
	if (*x > x_mid) {
		*x = x_mid - (*x - x_mid);
	}

	if (*y > y_mid) {
		*y = y_mid - (*y - y_mid);
	}	
}

int traverse_square(int x_mid, int y_mid, int size, int x_tgt, int y_tgt)
{
	if (size == 0) {
		return 0;
	}

	trans_point(x_mid, y_mid, &x_tgt, &y_tgt);

	if (x_tgt >= x_mid - size && x_tgt <= x_mid && y_tgt >= y_mid - size && y_tgt <= y_mid) {
		return 1 + traverse_square(x_mid - size, y_mid - size, size / 2, x_tgt, y_tgt);
	}
	else {
		return traverse_square(x_mid - size, y_mid - size, size / 2, x_tgt, y_tgt);
	}

}

int main()
{
	int	size, x_tgt, y_tgt;

	while (scanf("%d %d %d\n", &size, &x_tgt, &y_tgt) != EOF) {
		if (size == 0 && x_tgt == 0 && y_tgt == 0) {
			break;
		}
		
		int result = traverse_square(1024, 1024, size, x_tgt, y_tgt);

		printf("%3d\n", result); 
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
