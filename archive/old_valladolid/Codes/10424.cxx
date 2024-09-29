/* @JUDGE_ID: andrea 10424 C++ "Simlulation" */
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
#define MAX(x, y)  	((x) > (y) ? (x) : (y))	// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))		// could be replaced with min(x, y) of <algorithm>
#define ABS(x)		((x) < 0 ? -1 * (x) : (x))

using namespace std;

class Solution { 
 public:
	inline int Compress(int);
	int CalculateNumber(string);
	int Run(); 

 private:
	string name;
};

inline int Solution::Compress(int num) {
	int comp = 0;
	while (num > 0) {
		comp += num % 10;
		num /= 10;
	}

	return comp;
}

int Solution::CalculateNumber(string name) {
	int num = 0;
	for (int i = 0; i < name.size(); i++) {
		if (isalpha(name[i])) {
			num += tolower(name[i]) - 'a' + 1;
		}
	}

	while (num >= 10) {
		num = Compress(num);
	}

	return num;
}

int Solution::Run() {
	string name_1, name_2;
	while (getline(cin, name_1)) {
		getline(cin, name_2);

		int n = CalculateNumber(name_1);
		int m = CalculateNumber(name_2);

		double result = (n > m) ? (double)m / n * 100.0 : (double)n / m * 100.0;

		printf("%.2lf ", result);
		puts("%");
	}

	return 0;
}

int main() {
	Solution sol;

	return sol.Run();

}
/* @END_OF_SOURCE_CODE */
