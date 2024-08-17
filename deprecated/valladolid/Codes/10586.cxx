/* @JUDGE_ID: andrea 10586 C++ "Simlulation" */
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
#define SWAP(x, y) 		((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define PSWAP(px, py, type)	\
do { \
	type* ptr = px;\
	px = py;\
	py = ptr;\
} while(0)\
#define MAX(x, y)  		((x) > (y) ? (x) : (y))	
#define MIN(x, y)		((x) < (y) ? (x) : (y))
#define ABS(x)			((x) < 0 ? -1 * (x) : (x))

using namespace std;

void find_remainder(int equation[], int n, int divider[], int k, int remainder[], int* r)
{
	int* eq  = &equation[0];
	int* div = &divider[0];
	int  temp[10240];
	int* tmp = &temp[0];

	while (1) {

		while (n > 0 && eq[n] == 0) {
			n--;
		}

		if ( (n > k) || (n == k && ABS(eq[n]) >= ABS(div[k])) ) {
			int mult = eq[n] / div[k];

			memcpy(tmp, &eq[0], sizeof(int) * (n + 1));
			for (int i = 0; i <= k; i++) {
				tmp[n - i] = tmp[n - i] - div[k - i] * mult;
			}

			PSWAP(eq, tmp, int);
		}
		else {
			memcpy(&remainder[0], &eq[0], sizeof(int) * (n + 1));
			*r = n;
			break;
		}
	}

	return;
}

int main()
{
	int n, k;
	int equation[10240], divider[10240], remainder[10240]; 

	while (scanf("%d %d\n", &n, &k) != EOF) {
		if (n == -1 && k == -1) {
			break;
		}

		for (int i = 0; i <= n; i++) {
			scanf("%d", &equation[i]);
		}

		memset(&divider[0], 0x0, sizeof(int) * (k + 1));
		divider[0] = 1;
		divider[k] = 1;

		int r;
		find_remainder(equation, n, divider, k, remainder, &r);

		printf("%d", remainder[0]);
		for (int i = 1; i <= r; i++) {
			printf(" %d", remainder[i]);
		}
		printf("\n");
	}

	return 0;		
}
/* @END_OF_SOURCE_CODE */
