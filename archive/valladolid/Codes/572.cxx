/* @JUDGE_ID: andrea 572 C++ "Simlulation" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

typedef struct {
	int row;
	int col;
} Pos;

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>
#define ABS(x)		((x) < 0 ? -1 * (x) : (x))

using namespace std;

#define MAX_ROW	100
#define MAX_COL	100

typedef struct {
	int row_dir;
	int col_dir;	
} Dir;

#define NUM_DIR	8

Dir direction[8] = {{-1, -1}, {-1, 0}, {-1, 1},
					{ 0, -1},          { 0, 1},
					{ 1, -1}, { 1, 0}, { 1, 1}}; 

char map[MAX_ROW + 2][MAX_COL + 2];

// Search Deposits using DFS
void DFS_map(int row, int col)
{
	map[row][col] = '*';

	for (int i = 0; i < NUM_DIR; i++) {
		
		int next_row = row + direction[i].row_dir;
		int next_col = col + direction[i].col_dir;

		if (map[next_row][next_col] == '@') {
			DFS_map(next_row, next_col);
		}		
	}

	return;
}

// Search Deposits using BFS
void BFS_map(int row, int col)
{
	queue<Pos>  q;
	Pos			pos = {row, col};

	q.push(pos);

	while (!q.empty()) {

		Pos pos = q.front();
		q.pop();
		map[pos.row][pos.col] = '*';

		for (int i = 0; i < 8; i++) {

			Pos next;
			next.row = pos.row + direction[i].row_dir;
			next.col = pos.col + direction[i].col_dir;

			if (map[next.row][next.col] == '@') {
				q.push(next);
			}
		}	
	}

	return;
}

int main()
{
	int m, n;

	while (scanf("%d %d\n", &m, &n) != EOF && m != 0) {

		// init map
		memset(&map[0][0], '*', sizeof(char) * MAX_ROW * MAX_COL);

		// read map
		for (int r = 1; r <= m; r++) {
			gets(&map[r][1]);
			map[r][n + 1] = '*';
		}

		// find oil deposits
		int num_deposits = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] == '@') {
					DFS_map(i, j);
					//BFS_map(i, j);
					num_deposits++;
				}
			}
		}

		printf("%d\n", num_deposits);
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
