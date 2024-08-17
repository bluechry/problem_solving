/* @JUDGE_ID: andrea 10365 C++ "Brute-Force Search */
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
#define ABS(x)		((x) < 0 ? -1 * (x) : (x))

using namespace std;

int main()
{
	int num_cases;

	scanf("%d\n", &num_cases);

	while (num_cases-- > 0) {

		/* read input */
		int	N;
		scanf("%d\n", &N);

		/* find minimum area */
		int i, j, k;
		int A, min_A;

		min_A = N * N * 6;
		for (i = 1; i <= N; i++) {
			for (j = 1; i * j <= N; j++) {
				for (k = 1; i * j * k <= N; k++) {
					if (i * j * k == N) {
						A = i * j * 2 + j * k * 2 + k * i * 2;
						if (A < min_A) min_A = A; 
					}
				}
			}
		}

		printf("%d\n", min_A);
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
