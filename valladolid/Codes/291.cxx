/* @JUDGE_ID: andrea 291 C++ "Simlulation" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <vector>
#include <cstdio>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>
#define ABS(x)		((x) < 0 ? -1 * (x) : (x))

using namespace std;

int matrix[6][6] = {{0, 0, 0, 0, 0, 0},
					{0, 0, 1, 1, 0, 1},
					{0, 1, 0, 1, 0, 1},
					{0, 1, 1, 0, 1, 1},
					{0, 0, 0, 1, 0, 1},
					{0, 1, 1, 1, 1, 0}};

vector<int> path; 

void traverse(int start)
{

	for (int i = 1; i <= 5; i++) {
		if (matrix[start][i] == 1) {
			path.push_back(i);
			matrix[start][i] = 0;
			matrix[i][start] = 0;

			traverse(i);

			path.pop_back();
			matrix[start][i] = 1;
			matrix[i][start] = 1;
		}
	}

	if (path.size() == 9) {
		for (int i = 0; i < path.size(); i++) {
			printf("%d", path[i]);
		}
		printf("\n");
	}

	return;
}

int main()
{
	path.push_back(1);
	traverse(1);
	path.pop_back();

	return 0;		
}

/* @END_OF_SOURCE_CODE */
