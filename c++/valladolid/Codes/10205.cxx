/* @JUDGE_ID: andrea 10205 C++ "Simlulation" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>
#define ABS(x)		((x) < 0 ? -1 * (x) : (x))

using namespace std;

char suites[][16] = {"Clubs", "Diamonds", "Hearts", "Spades"};
char values[][16] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

int main()
{
	int num_cases;

	scanf("%d\n", &num_cases);

	bool isFirst = 1;
	while (num_cases-- > 0) {

		// get # of shuffle		
		int num_shuffle;
		scanf("%d\n", &num_shuffle);

		// init deck
		int deck_1[64], deck_2[64];
		int* result = deck_1;
		int* temp 	= deck_2;
		int* ptr;

		for (int i = 1; i <= 52; i++) {
			result[i] = i;
		}

		// record each shuffle
		int suffle[128][64];
		for (int i = 1; i <= num_shuffle; i++) {
			for (int j = 1; j <= 52; j++) {
				scanf("%d", &suffle[i][j]);
			}
		}

		// get shuffle ID
		char line[16];

		fgets(line, 16, stdin);	
		while (fgets(line, 16, stdin) != NULL && line[0] != '\n') {
			int current = atoi(line);

			for (int i = 1; i <= 52; i++) {
				temp[i] = result[suffle[current][i]];
			}

			ptr = result;
			result = temp;
			temp = ptr;
		}

		// output the suffled deck
		if (!isFirst) {
			printf("\n");
		}
		else {
			isFirst = 0;
		}

		for (int i = 1; i <= 52; i++) {
			int suite_id = (result[i] - 1) / 13;
			int value_id = (result[i] - 1) - suite_id * 13;

			printf("%s of %s\n", values[value_id], suites[suite_id]);
		}
	} 	

	return 0;		
}

/* @END_OF_SOURCE_CODE */
