/* @JUDGE_ID: andrea 11498 C++ "Simple Math" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files for C++
 */
#include <iostream>
#include <algorithm>

/*
 * Header Files for C
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)

#define PSWAP(px, py, type) \
do { \
    type* ptr = px;\
    px = py;\
    py = ptr;\
} while(0)

#define ABS(x)		((x) < 0 ? -1 * (x) : (x))

/*
 * Namespace(s)
 */
using namespace std;

int main() {
	int  num_cases;
	while (scanf("%d\n", &num_cases)) {
		/* parse the # of test cases */
		if (num_cases == 0) {
			break;
		}

		/* parse the division point */
		int div_x, div_y;
		scanf("%d %d\n", &div_x, &div_y);

		/* parse the positions of residences */
		for (int i = 0; i < num_cases; i++) {
			int x, y;
			scanf("%d %d\n", &x, &y);

			if (x == div_x || y == div_y) {
				puts("divisa");
				continue;
			}

			string result;
			(y > div_y) ? result += "N" : result += "S";
			(x > div_x) ? result += "E" : result += "O";

			puts(result.c_str());
		}	
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
