/* @JUDGE_ID: andrea 514 C++ "Simulation" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <vector>
#include <stack>
#include <cstdio>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>

using namespace std;

bool check_perm(const vector<int>& v, int N)
{
	stack<int>	s;
	int 		num;

	s.push(-1);
	num = 1;

	for (vector<int>::const_iterator iter = v.begin(); iter != v.end(); iter++) {

		while (num <= N && s.top() != *iter) {
			s.push(num++);
		}

		if (s.top() == *iter) {
			s.pop();
		}
		else {
			break;
		}

	}

	if (s.top() == -1) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	int	N, count;

	count = 0;
	while (scanf("%d\n", &N) != EOF && N != 0) {

		vector<int> v;
		int 		temp;

		v.reserve(N);	
		while (scanf("%d", &temp) && temp != 0) {

			v.push_back(temp);

			if (v.size() == N) {
				if (check_perm(v, N)) {
					puts("Yes");
				}
				else {
					puts("No");
				}

				v.erase(v.begin(), v.end());
			}
		}
		printf("\n");
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
