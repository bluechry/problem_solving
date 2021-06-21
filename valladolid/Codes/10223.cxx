/* @JUDGE_ID: andrea 10223 C++ "Number Theory" */
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
	unsigned int catalan[20] = {1,       1,        2,         5,         14,
								42,      132,      429,       1430,      4862,
								16796, 	 58786,    208012,    742900,    2674440,
								9694845, 35357670, 129644790, 477638700, 1767263190};

	unsigned int n;

	while (cin >> n) {
	
		int i;	
		for (i = 1; i < 20; i++) {
			if (catalan[i] >= n) {
				break;
			}
		}
		
		cout << i << '\n';
	}
	

	return 0;		
}

/* @END_OF_SOURCE_CODE */
