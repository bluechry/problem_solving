/* @JUDGE_ID: andrea xxx C++ "Simlulation" */
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

int main()
{
	int remainder[10][5] = {{0}, 
							{1}, 
							{2, 4, 8, 6}, 
							{3, 9, 7, 1}, 
							{4, 6}, 
							{5}, 
							{6}, 
							{7, 9, 3, 1}, 
							{8, 4, 2, 6}, 
							{9, 1}};

	int num_remainder[10] = {1, 1, 4, 4, 2, 1, 1, 4, 4, 2};

	char M[128], N[128];

	while (scanf("%s %s\n", M, N) != EOF) {

		if (M[0] == '0' && N[0] == '0') {
			break;
		}

		if (M[0] == '0') {
			printf("%d\n", 0);
			continue;
		}

		if (N[0] == '0') {
			printf("%d\n", 1);
			continue;
		}
	
		int len_m, len_n;
		int m, n;

		len_m = strlen(M);
		len_n = strlen(N);

		m = atoi(&M[len_m - 1]);
		n = (len_n >= 2) ? atoi(&N[len_n - 2]) : atoi(&N[len_n - 1]);
		n = (n == 0) ? 100 : n;

		m = m % 10;
		n = (n - 1) % num_remainder[m];

		printf("%d\n", remainder[m][n]);
	}	

	return 0;		
}

/* @END_OF_SOURCE_CODE */
