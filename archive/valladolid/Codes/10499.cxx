/* @JUDGE_ID: andrea 10499 C++ "Geometry" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>

using namespace std;

int main()
{
	long long	N, profit;

	while (cin >> N) {
		if (N < 0) {
			break;
		}

		profit = (N == 1) ? 0 : 25 * N;

		cout << profit << '%' << endl;
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
