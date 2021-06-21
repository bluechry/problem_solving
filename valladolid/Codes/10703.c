/* @JUDGE_ID: andrea 10703 C "Simpel Iteration" */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <string.h>

#define MAX_WIDTH	501
#define MAX_HEIGHT	501

#define SWAP(x, y, t) (t) = (x), (x) = (y), (y) = (t)

int main()
{
	int		width, height, num_subboard;
	int		x1, y1, x2, y2;
	char	board[MAX_WIDTH][MAX_HEIGHT];
	int		i, j, k, temp;
	int		count;
	char	dummy[1 << 2];

	while(scanf("%d %d %d", &width, &height, &num_subboard) == 3) {
		if (!width && !height && !num_subboard) break;

		memset(board, 0, MAX_WIDTH * MAX_HEIGHT * sizeof(char));

		for (i = 0; i < num_subboard; i++) {
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			if (x1 > x2) SWAP(x1, x2, temp);
			if (y1 > y2) SWAP(y1, y2, temp);
	
			for (j = x1; j <= x2; j++) 
				for (k = y1; k <= y2; k++)
					board[j][k] = 1;
		}

		for (count = 0, j = 1; j <= width; j++) 
			for (k = 1; k <= height; k++) 
				if (!board[j][k]) count++;
		
		switch (count) {
		case 0:
			printf("There is no empty spots.\n");
			break;
		case 1:
			printf("There is one empty spot.\n");
			break;
		default:
			printf("There are %d empty spots.\n", count);	
			break;
		}
	
		gets(dummy);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
