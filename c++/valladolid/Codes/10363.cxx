/* @JUDGE_ID: andrea 10363 C++ "Simlulation" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>
#define ABS(x)		((x) < 0 ? -1 * (x) : (x))

using namespace std;

int main()
{
	int num_cases;

	scanf("%d\n", &num_cases);
	while (num_cases-- > 0) {

		// read tic-tac-toe board and count # of X and O
		char board[3][3];
		for (int i = 0; i < 3; i++) {
			scanf("%c%c%c\n", &board[i][0], &board[i][1], &board[i][2]);
		}

		// count # of X and O
		int  num_X = 0, num_O = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				switch (board[i][j]) {
				case 'X':
					num_X++;
					break;
				case 'O':
					num_O++;
					break;
				}
			}
		}

		// find a winner
		bool win_X = false, win_O = false;
		for (int i = 0; i < 3; i++) {
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
				switch (board[i][0]) {
				case 'X':
					win_X = true;
					break;
				case 'O':
					win_O = true;
					break;
				}
			}

			if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
				switch (board[0][i]) {
				case 'X':
					win_X = true;
					break;
				case 'O':
					win_O = true;
					break;
				}
			}
		}

		if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
			(board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
			if (board[1][1] == 'X') {
				win_X = true;
			}
			else {
				win_O = true;
			}
		}
	
		// check validity of the board
		if (win_X == true && win_O == false && num_X == num_O + 1) {
			puts("yes");
		}
		else if (win_X == false && win_O == true && num_X == num_O) {
			puts("yes");	
		}
		else if (win_X == false && win_O == false && (num_X == num_O || num_X == num_O + 1)) {
			puts("yes");
		}
		else {
			puts("no");
		}
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */
