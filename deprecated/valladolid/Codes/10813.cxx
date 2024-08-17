/* @JUDGE_ID: andrea xxx C++ "Simlulation" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <cstdio>
#include <cstring>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>
#define ABS(x)		((x) < 0 ? -1 * (x) : (x))

using namespace std;

typedef struct {
	int row;
	int col;
} Number;

int main()
{
	int num_games;

	scanf("%d\n", &num_games);

	while (num_games-- > 0) {

		/* Record location of each number */
		Number number[128];

		for (int i = 0; i < 128; i++) {
			number[i].row = -1;
			number[i].col = -1;
		}

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (i == 2 && j == 2) {
					continue;
				}	

				int num;

				scanf("%d", &num);
				number[num].row = i;
				number[num].col = j;	
			}
		}

		/* Read numbers and check bingo! */
		int row_sum[8], col_sum[8];
		int diag_sum1, diag_sum2;

		memset(row_sum, 0x0, sizeof(int) * 8);
		memset(col_sum, 0x0, sizeof(int) * 8);

		row_sum[2] = col_sum[2] = 1;
		diag_sum1 = diag_sum2 = 1;

		int count = 0;
		for (int i = 0; i < 75; i++) {

			/* read and mark a number */
			int num;

			scanf("%d", &num);
			
			if (count > 0 || number[num].row < 0) {
				continue;
			}

			if (number[num].row == number[num].col) {
				diag_sum1++;
			}
			else if (number[num].row == 4 - number[num].col) {
				diag_sum2++;
			}

			row_sum[number[num].row]++;
			col_sum[number[num].col]++;

			/* check bingo */	
			if (diag_sum1 == 5 || diag_sum2 == 5) {
				count = i;
				continue;
			}

			for (int j = 0; j < 5; j++) {
				if (row_sum[j] == 5 || col_sum[j] == 5) {
					count = i;
					break;
				}
			}
		}

		printf("BINGO after %d numbers announced\n", count + 1);
	}
	
	return 0;		
}

/* @END_OF_SOURCE_CODE */
