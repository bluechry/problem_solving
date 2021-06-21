/* @JUDGE_ID: andrea 10285 C++ "Simlulation" */
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

#define MAX_SZ		128

using namespace std;

typedef struct {
	int r, c;
} Dir;

Dir direction[] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

int height[MAX_SZ][MAX_SZ];
int length[MAX_SZ][MAX_SZ];

int get_path_length(int r, int c)
{
	if (length[r][c] > 0) {
		return length[r][c];
	}

	int max = 0;
	for (int i = 0; i < 4; i++) {
		if (height[r][c] > height[r + direction[i].r][c + direction[i].c]) {
			int len = get_path_length(r + direction[i].r, c + direction[i].c);	
			if (len > max) {
				max = len;
			}
		}
	}

	length[r][c] = 1 + max;

	return length[r][c]; 
}

int main()
{
	char	name[128];
	int		N, R, C;

	// read # of cases
	scanf("%d\n", &N);
	while (N-- > 0) {

		// init height matrix & length matrix
		memset(&height[0][0], 0x1, sizeof(int) * MAX_SZ * MAX_SZ);
		memset(&length[0][0], 0x0, sizeof(int) * MAX_SZ * MAX_SZ);

		// read name, # of rows, # of cols
		scanf("%s %d %d\n", name, &R, &C);

		// read heights
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				scanf("%d", &height[i][j]);
			}
		}

		// find longest path length
		int max = 0; 
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				int len = get_path_length(i, j);
				if (len > max) {
					max = len;
				}
			}
		}

		printf("%s: %d\n", name, max);
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
