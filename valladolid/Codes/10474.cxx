/* @JUDGE_ID: andrea 10474 C++ "Simlulation" */
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
	int count[10240];
	int position[10240];

	int N, Q;
	int cases;

	cases = 1;
	while (scanf("%d %d\n", &N, &Q) != EOF) {

		memset(&count[0], 0x0, sizeof(int) * 10240);
		memset(&position[0], -1, sizeof(int) * 10240);

		if (N == 0 && Q == 0) { 
			break;
		}

		// read numbers & count # of occurences
		for (int i = 0; i < N; i++) {
			int n;

			scanf("%d\n", &n);
			count[n]++;	
		}

		// find positions of each number
		int next_pos = 0;
		for (int i = 0; i <= 10000; i++) {
			if (count[i] > 0) {
				position[i] = next_pos;
				next_pos += count[i];
			}
		}

		// read queries & output result
		printf("CASE# %d:\n", cases++);

		for (int i = 0; i < Q; i++) {
			int q;

			scanf("%d\n", &q);
		
			int pos = position[q];

			if (pos < 0) {
				printf("%d not found\n", q);
			}
			else {
				printf("%d found at %d\n", q, position[q] + 1); 
			}
		}

	}

	return 0;		
}
/* @END_OF_SOURCE_CODE */
