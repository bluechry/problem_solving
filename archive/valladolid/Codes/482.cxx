/* @JUDGE_ID: andrea 482 C++ "Simlulation" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <vector>
#include <string>

#include <cstdio>
#include <cstdlib>
#include <cctype>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>
#define ABS(x)		((x) < 0 ? -1 * (x) : (x))

using namespace std;

void string_split(string s, vector<string>& v)
{
	string::size_type i;

	i = 0;
	while (i != s.size()) {

		while (i != s.size() && isspace(s[i]))
			i++;

		string::size_type j = i;
		while (j != s.size() && !isspace(s[j]))
			j++;

		if (i != j) {
			v.push_back(s.substr(i, j - i));
			i = j;
		}
	}

	return;
}

int main()
{
	int 	num_cases;
	string 	temp;
	bool	isFirst;
	
	cin >> num_cases;
	getline(cin, temp);		// skip a '\n' 

	isFirst = true;
	while (num_cases-- > 0) {
	
		getline(cin, temp);	// skip a blank line

		// read a line & extract indice
		string idx;
		getline(cin, idx);
		
		vector<string> idx_vec;
		string_split(idx, idx_vec);

		// read a line & extract numbers
		string num;
		getline(cin, num);

		vector<string> num_vec;
		string_split(num, num_vec);
		
		// rearrange numbers
		string* result = new string[sizeof(string) * num_vec.size()];

		for (int i = 0; i < idx_vec.size(); i++) {
			int pos = atoi(idx_vec[i].c_str()) - 1;

			result[pos] = num_vec[i];
		}

		// output a result
		if(isFirst) {
			isFirst = false;
		}
		else {
			cout << endl;
		}

		for (int i = 0; i < num_vec.size(); i++) {
			cout << result[i] << endl;
		}

		delete [] result; 
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
