/* @JUDGE_ID: andrea 10450 C++ "Simlulation" */
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

unsigned long long calc_fib(int n)
{
	if (n == 1) return 2;
	if (n == 2) return 3;

	unsigned long long f_2 = 2, f_1 = 3, f = 0;

	for (int i = 3; i <= n; i++) {
		f = f_2 + f_1;
		f_2 = f_1;
		f_1 = f; 
	}

	return f;
}

int main()
{
	int num_cases;

	scanf("%d\n", &num_cases);
	for (int c = 1; c <= num_cases; c++) {
		int n;
		
		scanf("%d\n", &n);

		printf("Scenario #%d:\n", c);
		printf("%llu\n", calc_fib(n));
		printf("\n");
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
