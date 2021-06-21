/* @JUDGE_ID: andrea 102 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <limits.h>

#define NUM_BIN		3
#define NUM_COLOR	3

int main()
{
	int 		bin[NUM_BIN][NUM_COLOR];
	char const	color[NUM_COLOR] = {'B', 'C', 'G'};
	int			i, j, k;
	int			num_move, min_move;
	int			color_1, color_2, color_3;

	while (scanf("%d %d %d %d %d %d %d %d %d", 	&bin[0][0], &bin[0][2], &bin[0][1], 
												&bin[1][0], &bin[1][2], &bin[1][1],
												&bin[2][0], &bin[2][2], &bin[2][1]) == 9) {

		min_move = INT_MAX;	

		/* Generate Permutation */
		for (i = 0; i < NUM_COLOR; i++) {
			for (j = 0; j < NUM_COLOR; j++) {
				for (k = 0; k < NUM_COLOR; k++) {
					if (i != j && j != k && k != i) {
						/* Calculate the number of move */
						num_move = 	bin[1][i] + bin[2][i] + bin[0][j] + bin[2][j] + bin[0][k] + bin[1][k];
				
						/* Check whether num_move is minimum or not */
						if (num_move < min_move) {
							min_move = num_move;
							color_1 = i, color_2 = j, color_3 = k;
						}
					}
				}
			}
		}
		
		printf("%c%c%c %d\n", color[color_1], color[color_2], color[color_3], min_move);	
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
