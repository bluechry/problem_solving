/* @JUDGE_ID: andrea 661 C++ "Simlulation" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

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
	int n, m, c;
	int capacity[32];
	int count;

	count = 0;
	while (scanf("%d %d %d\n", &n, &m, &c) != EOF) {

		if (n + m + c == 0) {
			break;
		}	

		// read capacity of each device
		for (int i = 1; i <= n; i++) {
			scanf("%d", &capacity[i]);
		}		

		// read operations & calculate the sum of total capacity
		int dev_no;
		int sum = 0, max = 0;

		for (int i = 0; i < m; i++) {
			scanf("%d\n", &dev_no);
			
			sum += capacity[dev_no];
			if (sum > max) {
				max = sum;
			}
			capacity[dev_no] *= -1;
		}

		// ouput a result
		printf("Sequence %d\n", ++count);
		if (max > c) {
			printf("Fuse was blown.\n");		
		}
		else {
			printf("Fuse was not blown.\n");
			printf("Maximal power consumption was %d amperes.\n", max);
		}
		printf("\n");
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
