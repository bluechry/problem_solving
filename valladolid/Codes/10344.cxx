/* @JUDGE_ID: andrea 10344 C++ "Backtracking" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>

using namespace std;

bool find_equation(vector<int>& num, vector<char>& op, int tgt)
{
	if (num.size() == 1) {
		if (num[0] == tgt) {
			return true;
		}
		else {
			return false; 
		}
	}

	int left, right;

	left = num.back();
	num.pop_back();

	right = num.back();
	num.pop_back();

	for (vector<char>::iterator iter = op.begin(); iter != op.end(); iter++) {
		switch (*iter) {
		case '+':
			num.push_back(left + right);
			break;
		case '-':
			num.push_back(left - right);
			break;
		case '*':
			num.push_back(left * right);
			break;
		default:
			break;
		}

		if (find_equation(num, op, tgt)) {
			return true;
		}

		num.pop_back();
	}

	// last, return false
	num.push_back(right);
	num.push_back(left);

	return false;
}

int main()
{
	char 			line[512];
	int				num[8];
	vector<int> 	v;
	vector<char> 	op;

	op.push_back('+');
	op.push_back('-');
	op.push_back('*');

	while (scanf("%d %d %d %d %d\n", &num[0], &num[1], &num[2], &num[3], &num[4]) != EOF) {

		if (!(num[0] || num[1] || num[2] || num[3] || num[4])) {
			break;
		}

		int max = 1, count_one = 0;
		for (int i = 0; i < 5; i++) {
			if (num[i] > 1) {
				max *= num[i];
			}
			else {
				count_one++;
			}
		}
		max += count_one;

		if (max < 23) {
			cout << "Impossible" << '\n';
			continue;
		}

		v.push_back(num[0]);
		v.push_back(num[1]);
		v.push_back(num[2]);
		v.push_back(num[3]);
		v.push_back(num[4]);

		sort(v.begin(), v.end());
		
		bool found = false;
		do {
			if (find_equation(v, op, 23)) {
				found = true;
				break;
			}
		} while (next_permutation(v.begin(), v.end()));

		if (found) {
			cout << "Possible" << '\n';
		}
		else {
			cout << "Impossible" << '\n';
		}

		v.clear();
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
