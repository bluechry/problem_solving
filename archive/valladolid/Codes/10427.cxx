/* @JUDGE_ID: andrea 10427 C++ "Arithmatic" */
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
#define PSWAP(px, py, type) \
do { \
    type* ptr = px;\
    px = py;\
    py = ptr;\
} while(0)
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>
#define ABS(x)		((x) < 0 ? -1 * (x) : (x))

using namespace std;

int main()
{
	int N;

	while (scanf("%d\n", &N) != EOF) {
		
		int i;
		int len = 0, power = 1;	
		for (i = 1; ; i++) {
			len += 9 * power * i;
			if (len >= N) break;
			power *= 10;
		}
		len -= 9 * power * i;

		int num = (N - len - 1) / i + power;

		int j = (N - len) % i;
		if (j == 0) j += i;

		num /= (int)pow(10.0, (double)(i - j));
		
		printf("%d\n", num % 10);
	}

	return 0;		
}
/* @END_OF_SOURCE_CODE */
