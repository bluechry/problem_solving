/* @JUDGE_ID: andrea 10189 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <string.h>

#define MAX_COLS	102
#define MAX_ROWS	102

int main()
{
	int 	in_field[MAX_ROWS][MAX_COLS];
	int 	out_field[MAX_ROWS][MAX_COLS];
	int 	n_rows, n_cols;
	int		i, j, field_id;
	char	line_buf[MAX_COLS];

	/* Set field_id to 1 */
	field_id = 1;
	
	/* Read input */	
	while (scanf("%d %d", &n_rows, &n_cols) == 2 && n_rows && n_cols) {
		// Set in_field to 0 
		memset(in_field, 0, MAX_ROWS * MAX_COLS * sizeof(int));

		// Fill in_field with given input
		for (i = 0; i < n_rows; i++) {
			scanf("%s", line_buf);
			for (j = 0; j < n_cols; j++) {
				if (line_buf[j] == '*') 
					in_field[i + 1][j + 1] = 1;
				else
					in_field[i + 1][j + 1] = 0;
			}
		}	

		// Calculate the number of mines and fill out_field
		for (i = 1; i <= n_rows; i++) {
			for (j = 1; j <= n_cols; j++) {
				if (in_field[i][j] == 1) 
					out_field[i][j] = -1;
				else {
					out_field[i][j] = in_field[i - 1][j - 1] + in_field[i - 1][j] + in_field[i - 1][j + 1]
									+ in_field[i][j - 1] + in_field[i][j + 1]
									+ in_field[i + 1][j - 1] + in_field[i + 1][j] + in_field[i + 1][j + 1];
				}
			}
		}
		
		// Print out_field
		if (field_id > 1)
			printf("\n");

		printf("Field #%d:\n", field_id++);
		for (i = 1; i <= n_rows; i++) {
			for (j = 1; j <= n_cols; j++) {
				if (out_field[i][j] == -1) 
					printf("*");
				else 
					printf("%d", out_field[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
