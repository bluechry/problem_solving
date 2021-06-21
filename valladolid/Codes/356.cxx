/* @JUDGE_ID: andrea 356 C++ "Geometry" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <cmath>
#include <cstdio>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>

using namespace std;

int main()
{
	double	n, r; 
	int		min, max;
	int 	all_cov, part_cov;
	int		count;

	count = 0;
	while (scanf("%lf\n", &n) != EOF) {

		r = (2.0 * n - 1) / 2.0;
		r = r * r; 

		all_cov = part_cov = 0;

		for (int i = 0; i < n; i++) {

			for (int j = 0; j < n; j++) {

				min = i * i + j * j;
				max = (i + 1) * (i + 1) + (j + 1) * (j + 1);

				if (r >= max) {
					all_cov++;
				}
				else if (r > min && r < max) {
					part_cov++;
				}
			}
		}

		if (count > 0) {
			printf("\n");
		}
		else {
			count = 1;
		}
	
		printf("In the case n = %0.lf, %d cells contain segments of the circle.\n", n, 4 * part_cov);
		printf("There are %d cells completely contained in the circle.\n", 4 * all_cov);
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
