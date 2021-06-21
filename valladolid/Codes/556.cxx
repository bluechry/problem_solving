/* @JUDGE_ID: andrea 556 C++ "Simulation" */
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
#define ABS(x)      ((x) < 0 ? -1 * (x) : (x))

using namespace std;

/*
 * Definitions
 */

/* for a board */
#define MAX_SIZE	128	
#define WALL		'1'	

char board[MAX_SIZE][MAX_SIZE];

/* for a moving */
typedef struct {
	int row;
	int col;
	int orient;		// 0: North, 1: East, 2: South, 3: West
} Position;

typedef struct {
	int row_dir;
	int col_dir;
} Direction;

Direction dir[4] = {{-1,  0}, 	// North
				  	{ 0,  1},	// East 
				  	{ 1,  0}, 	// South
					{ 0, -1}};	// West

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

inline void turn_back(Position& pos)
{
	pos.orient = (pos.orient + 2) % 4;

	return;
}

inline bool check_front(Position& pos)
{
	Position temp = pos;

	temp.row += dir[temp.orient].row_dir;
	temp.col += dir[temp.orient].col_dir;

	return (board[temp.row][temp.col] == WALL) ? false : true;
}

inline bool check_rear(Position& pos)
{
	Position temp = pos;

	turn_back(temp);
	
	temp.row += dir[temp.orient].row_dir;
	temp.col += dir[temp.orient].col_dir;

	return (board[temp.row][temp.col] == WALL) ? false : true;
}

inline bool check_right(Position& pos)
{
	Position temp = pos;

	turn_right(temp);
	
	temp.row += dir[temp.orient].row_dir;
	temp.col += dir[temp.orient].col_dir;

	return (board[temp.row][temp.col] == WALL) ? false : true;
}

inline bool check_left(Position& pos)
{
	Position temp = pos;

	turn_left(temp);
	
	temp.row += dir[temp.orient].row_dir;
	temp.col += dir[temp.orient].col_dir;

	return (board[temp.row][temp.col] == WALL) ? false : true;
}

inline void go_forward(Position& pos)
{
	pos.row += dir[pos.orient].row_dir;
	pos.col += dir[pos.orient].col_dir;

	return;
}

inline void dump(int num_rows, int num_cols)
{
	for (int i = 1; i <= num_rows; i++) {
		for (int j = 1; j <= num_cols; j++) {
			if (board[i][j] < '0') {
				printf("%3d", ABS(board[i][j] - '0'));
			}
			else {
				printf("%3d", board[i][j] - '0');
			}
		}
		printf("\n");
	}
	printf("\n");

	return;
}

inline void run(int num_rows, int num_cols)
{
	Position robot;

	robot.orient = 1;
	robot.row 	 = num_rows;
	robot.col 	 = 1;

	// move a robot
	do {

		if (check_right(robot) == false && check_front(robot) == true) {
			board[robot.row][robot.col] += -1;		
			go_forward(robot);
		}
		else if (check_right(robot) == false && check_front(robot) == false) {
			int count = 0;
			while (check_front(robot) == false) {
				turn_left(robot);
				if (++count >= 4) {
					break;
				}
			}

			if (count < 4) {
				board[robot.row][robot.col] += -1;
				go_forward(robot);
			}

		}
		else if (check_right(robot) == true) {
			board[robot.row][robot.col] += -1;		
			turn_right(robot);
			go_forward(robot);
		}

	} while (robot.row != num_rows || robot.col != 1);  


	// count # of visits
	int num_0, num_1, num_2, num_3, num_4;

	num_0 = num_1 = num_2 = num_3 = num_4 = 0;
	for (int i = 1; i <= num_rows; i++) {
		for (int j = 1; j <=num_cols; j++) {
			switch (board[i][j] - '0') {
			case 0:
				num_0++;
				break;
			case -1:
				num_1++;
				break;
			case -2:
				num_2++;
				break;
			case -3:
				num_3++;
				break;
			case -4:
				num_4++;
				break;
			default:
				break;
			}
		}
	}

	printf("%3d%3d%3d%3d%3d\n", num_0, num_1, num_2, num_3, num_4);	

	return ;
}

int main()
{
	int	num_rows, num_cols;

	while (scanf("%d %d\n", &num_rows, &num_cols) != EOF) {

		if (num_rows == 0 && num_cols == 0) {
			break;
		}

		// init a board
		memset(&board[0][0], WALL, sizeof(char) * MAX_SIZE * MAX_SIZE);

		// store a board
		for (int r = 1; r <= num_rows; r++) {
			gets(&board[r][1]);
			board[r][num_cols + 1] = WALL;
		}

		// run
		run(num_rows, num_cols);
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */
