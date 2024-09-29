/* @JUDGE_ID: andrea 10377 C++ "Simulation" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <cstring>
#include <cstdio>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>

using namespace std;

/*
 * Definitions
 */

/* for a maze */
#define MAX_SIZE	64

char maze[MAX_SIZE][MAX_SIZE];

/* for a moving */
typedef struct {
	int row;
	int col;
	int orient;
} Position;

typedef struct {
	int row_dir;
	int col_dir;
} Direction;

Direction	dir[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

inline void turn_right(Position& pos)
{
	pos.orient = (pos.orient + 1) % 4;

	return;
}

inline void turn_left(Position& pos)
{
	pos.orient = (pos.orient + 3) % 4;

	return;
}

inline void go_forward(Position& pos)
{
	Position temp = pos;

	temp.row += dir[temp.orient].row_dir;
	temp.col += dir[temp.orient].col_dir;

	if (maze[temp.row][temp.col] != '*') {
		pos = temp;
	}

	return;
}

inline void print_position(Position& pos)
{
	printf("%d %d ", pos.row, pos.col);

	switch (pos.orient) {
	case 0:
		printf("N\n");
		break;
	case 1:
		printf("E\n");
		break;
	case 2:
		printf("S\n");
		break;
	case 3:
		printf("W\n");
		break;
	default:
		break;
	}

	return;
}

int main()
{
	int			num_cases;
	int 		num_rows, num_cols;
	Position	robot_pos;

	scanf("%d\n", &num_cases);	
	for (int i = 1; i <= num_cases; i++) {

		// init a maze
		memset(&maze[0][0], '*', sizeof(char) * MAX_SIZE * MAX_SIZE);

		// store num_rows & num_cols
		scanf("%d %d\n", &num_rows, &num_cols);

		// store a maze
		for (int r = 1; r <= num_rows; r++) {
			gets(&maze[r][1]);
			maze[r][num_cols + 1] = '*';
		}

		// set initial position
		int start_row, start_col;
		scanf("%d %d\n", &start_row, &start_col);
		robot_pos.orient = 0;
		robot_pos.row = start_row;
		robot_pos.col = start_col;
		

		// process commands
		char ch;
		while ((ch = getchar()) != 'Q') {
			switch (ch) {
			case 'R':
				turn_right(robot_pos);
				break;
			case 'L':
				turn_left(robot_pos);
				break;
			case 'F':
				go_forward(robot_pos);
				break;
			default:
				break;
			}
		}		

		// print final position
		if (i > 1) {
			putchar('\n');
		}
		print_position(robot_pos);
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */
