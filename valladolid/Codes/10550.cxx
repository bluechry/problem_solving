/* @JUDGE_ID: andrea 10550 C++ "Simlulation" */
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
#define ABS(x)		((x) < 0 ? -1 * (x) : (x))

using namespace std;

typedef enum {CLK, CNT_CLK} Dir;

inline int calc_degree(int cur, int next, Dir dir) 
{
	int result;

	if (dir == CNT_CLK) {
		if (cur <= next) {
			result = next - cur;
		}
		else {
			result = 40 + next - cur;
		}
	}
	else {
		if (cur <= next) {
			result = cur + 40 - next;
		}
		else {
			result = cur - next;	
		}
	}

	return result; 
}

int main()
{
	int num0, num1, num2, num3;

	while (cin >> num0 >> num1 >> num2 >> num3) {

		if ((num0 | num1 | num2 | num3) == 0) {
			break;
		}
	
		int result = 0;

		result += calc_degree(num0, num1, CLK) + 40 * 2;

		result += calc_degree(num1, num2, CNT_CLK) + 40;

		result += calc_degree(num2, num3, CLK);

		cout << result * 9 << endl;
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
