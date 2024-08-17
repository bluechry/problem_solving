/* @JUDGE_ID: andrea 10196 C "Simulation" */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <string.h>

#define	BOARD_SIZE		12
#define	REAL_BOARD_SIZE	8
#define	BOARD_START 	2
#define BOARD_END		9

#define CHECK_ROOK_QUEEN(i, j)\
	if (chess_board[i][j] == opp_rook || chess_board[i][j] == opp_queen) {\
		return 1;\
	}

#define CHECK_BISHOP_QUEEN(i, j)\
	if (chess_board[i][j] == opp_bishop || chess_board[i][j] == opp_queen) {\
		return 1;\
	}

int check_the_check(char chess_board[BOARD_SIZE][BOARD_SIZE], int i, int j)
{
	int		is_black_king;
	char 	king;
	char 	opp_king, opp_queen, opp_knight, opp_rook, opp_bishop, opp_pawn;
	int		next_i, next_j;

	/* Initialize variables */
	is_black_king = islower(chess_board[i][j]);

	opp_king = is_black_king ? 'K' : 'k';
	opp_queen = is_black_king ? 'Q' : 'q';
	opp_knight = is_black_king ? 'N' : 'n';
	opp_rook = is_black_king ? 'R' : 'r';
	opp_bishop = is_black_king ? 'B' : 'b';
	opp_pawn = is_black_king ? 'P' : 'p';

	/* Check position of knights */
	if (chess_board[i - 2][j - 1] == opp_knight || chess_board[i - 1][j - 2] == opp_knight ||
		chess_board[i + 2][j - 1] == opp_knight || chess_board[i + 1][j - 2] == opp_knight ||
		chess_board[i - 2][j + 1] == opp_knight || chess_board[i - 1][j + 2] == opp_knight ||
		chess_board[i + 2][j + 1] == opp_knight || chess_board[i + 1][j + 2] == opp_knight) {
		return 1;
	}
	
	/* Check position of pawns */
	if (is_black_king) {
		if (chess_board[i + 1][j - 1] == opp_pawn || chess_board[i + 1][j + 1] == opp_pawn) 
			return 1;
	}
	else {
		if (chess_board[i - 1][j - 1] == opp_pawn || chess_board[i - 1][j + 1] == opp_pawn) 
			return 1;
	}
	
	/* Check left */
	for (next_i = i, next_j = j - 1; next_j > BOARD_START; --next_j) {
		if (chess_board[next_i][next_j] != '.')
			break;
	}
	CHECK_ROOK_QUEEN(next_i, next_j);

	/* Check right */
	for (next_i = i, next_j = j + 1; next_j < BOARD_END; ++next_j) {
		if (chess_board[next_i][next_j] != '.')
			break;
	}
	CHECK_ROOK_QUEEN(next_i, next_j);

	/* Check up */
	for (next_i = i - 1, next_j = j; next_i > BOARD_START; --next_i) {
		if (chess_board[next_i][next_j] != '.')
			break;
	}
	CHECK_ROOK_QUEEN(next_i, next_j);

	/* Check down */
	for (next_i = i + 1, next_j = j; next_i < BOARD_END; ++next_i) {
		if (chess_board[next_i][next_j] != '.')
			break;
	}
	CHECK_ROOK_QUEEN(next_i, next_j);

	/* Check upper left */
	for (next_i = i - 1, next_j = j - 1; next_i > BOARD_START && next_j > BOARD_START; --next_i, --next_j) {
		if (chess_board[next_i][next_j] != '.')
			break;
	}
	CHECK_BISHOP_QUEEN(next_i, next_j);
	
	/* Check upper right */
	for (next_i = i - 1, next_j = j + 1; next_i > BOARD_START && next_j < BOARD_END; --next_i, ++next_j) {
		if (chess_board[next_i][next_j] != '.')
			break;
	}
	CHECK_BISHOP_QUEEN(next_i, next_j);

	/* Check lower left */
	for (next_i = i + 1, next_j = j - 1; next_i < BOARD_END && next_j > BOARD_START; ++next_i, --next_j) {
		if (chess_board[next_i][next_j] != '.')
			break;
	}
	CHECK_BISHOP_QUEEN(next_i, next_j);

	/* Check lower right */
	for (next_i = i + 1, next_j = j + 1; next_i < BOARD_END && next_j < BOARD_END; ++next_i, ++next_j) {
		if (chess_board[next_i][next_j] != '.')
			break;
	}
	CHECK_BISHOP_QUEEN(next_i, next_j);

	return 0;
}

int main()
{
	char 	chess_board[BOARD_SIZE][BOARD_SIZE];
	char 	empty_board[BOARD_SIZE][BOARD_SIZE];
	char	line[16], piece;
	int		count, i, j;
	int		i_black_king, j_black_king, i_white_king, j_white_king;

	/* Set empty board */
	memset(chess_board, '.', BOARD_SIZE * BOARD_SIZE * sizeof(char));
	memset(empty_board, '.', BOARD_SIZE * BOARD_SIZE * sizeof(char));

	count = 0;
	while (1) {
		++count;

		/* Init chess board and find locations of two kings */
		for (i = 0; i < REAL_BOARD_SIZE; i++) {
			gets(line);
			for (j = 0; j < REAL_BOARD_SIZE; j++) {
				piece = chess_board[i + 2][j + 2] = line[j]; 
				
				if (piece == 'k') 
					i_black_king = i + 2, j_black_king = j + 2;
				else if (piece == 'K') 
					i_white_king = i + 2, j_white_king = j + 2;
			}
		}
		gets(line);	
		
		/* Check escape condition */
		if (memcmp(chess_board, empty_board, BOARD_SIZE * BOARD_SIZE * sizeof(char)) == 0)
			break;
		
		/* Check the check */
		if (check_the_check(chess_board, i_black_king, j_black_king)) 
			printf("Game #%d: black king is in check.\n", count);
		else if (check_the_check(chess_board, i_white_king, j_white_king)) 
			printf("Game #%d: white king is in check.\n", count);	
		else 
			printf("Game #%d: no king is in check.\n", count);	
	}	

	return 0;
}
/* @END_OF_SOURCE_CODE */
