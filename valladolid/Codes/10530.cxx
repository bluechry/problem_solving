/* @JUDGE_ID: andrea 10530 C++ "Simlulation*/
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

using namespace std;

int main()
{
	int		num;
	string	transcript;
	int		high, low, temp;

	low  = 1;
	high = 10;
	while (scanf("%d\n", &num) != EOF && num != 0) {

		getline(cin, transcript);

		if (transcript == "too high") {
			if ((temp = num - 1) < high) {
				high = temp;
			}
		}
		else if (transcript == "too low") {
			if ((temp = num + 1) > low) {
				low = temp;
			}
		}
		else if (transcript == "right on") {

			if (low <= num && num <= high) { 
				puts("Stan may be honest");
			}
			else {
				puts("Stan is dishonest");
			}
		
			low  = 1;
			high = 10;
		}
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
