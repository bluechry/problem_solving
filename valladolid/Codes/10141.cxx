/* @JUDGE_ID: andrea 10141 C++ "Ad Hoc" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <string>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>

using namespace std;

typedef struct {
	string 	name;
	double 	cost;
	int		num_spec;
} Proposal;

int main()
{
	int			num_req, num_prop;
	string		temp;
	Proposal	result, current;	
	int			i, j, count;

	count = 0;
	while (cin >> num_req >> num_prop) {
		
		if (num_req == 0 && num_prop == 0) {
			break;
		}

		// skip requirements
		getline(cin, temp);
		for (i = 0; i < num_req; i++) {
			getline(cin, temp);
		}

		// read the first proposal
		getline(cin, result.name);
		cin >> result.cost >> result.num_spec;

		getline(cin, temp);
		for (i = 0; i < result.num_spec; i++) {
			getline(cin, temp);
		}

		// compare the first proposal with rest ones	
		for (i = 0; i < num_prop - 1; i++) {
			getline(cin, current.name);
			cin >> current.cost >> current.num_spec;

			getline(cin, temp);
			for (j = 0; j < current.num_spec; j++) {
				getline(cin, temp);
			} 

			if ((current.num_spec > result.num_spec) ||
			 	(current.num_spec == result.num_spec && current.cost < result.cost)) { 
				result = current;
			}
		}

		// print result proposal
		if (count > 0) {
			cout << endl;
		}	
		cout << "RFP #" << ++count << endl;
		cout << result.name << endl;	
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
