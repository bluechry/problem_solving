/* @JUDGE_ID: andrea 10489 C++ "Ad Hoc" */
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
	int T;

	scanf("%d\n", &T);
	while (T-- > 0) {
		int N, B;
		int box[128];

		scanf("%d %d\n", &N, &B);

		for (int i = 0; i < B; i++) {
			box[i] = 1;
		} 

		for (int i = 0; i < B; i++) {
			int K;

			scanf("%d\n", &K);
		
			for (int j = 0; j < K; j++) {
				int a;
				scanf("%d", &a);	

				box[i] = (box[i] * (a % N)) % N;
			}		
		}

		int sum = 0;
		for (int i = 0; i < B; i++) {
			sum += box[i];
		}

		printf("%d\n", sum % N);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
