/* @JUDGE_ID: andrea 441 C++ "Brute Force" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <cstdio>
#include <vector>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>

using namespace std;

int main()
{
	int 		num_elems;
	vector<int> v;
	bool		is_first = true;

	v.reserve(16);
	while (scanf("%d", &num_elems) != EOF && num_elems != 0) {

		// store input to a vector
		for (int i = 0; i < num_elems; i++) {
			int num;
			scanf("%d", &num);
			v.push_back(num);
		}

		// print all combinations
		if (is_first) {
			is_first = false; 
		}
		else {
			printf("\n");
		}

		for (int x1 = 0; x1 < num_elems - 5; x1++) {
			for (int x2 = x1 + 1; x2 < num_elems - 4; x2++) {
				for (int x3 = x2 + 1; x3 < num_elems - 3; x3++) {
					for (int x4 = x3 + 1; x4 < num_elems - 2; x4++) {
						for (int x5 = x4 + 1; x5 < num_elems - 1; x5++) {
							for (int x6 = x5 + 1; x6 < num_elems; x6++) {
								printf("%d %d %d %d %d %d\n", v[x1], v[x2], v[x3], v[x4], v[x5], v[x6]);
							}
						}
					}
				}
			}
		}

		// clear the vector
		v.clear();
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
