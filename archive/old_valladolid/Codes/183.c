/* @JUDGE_ID: andrea 183 C "Ad Hoc" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <string.h>

#define MAX_DIM		256
#define ALIGN		50	


void convert_B_to_D(char bitmap[][MAX_DIM], int row_start, int row_end, int col_start, int col_end, int *num_print)
{
	int  		i, j;
	int  		bit_sum;
	int  		row_mid, col_mid;

	/* check valid bitmap */
	if (row_start > row_end || col_start > col_end) {
		return;
	}

	/* check all bits are 0 or 1 */
	bit_sum = 0; 
	for (i = row_start; i <= row_end; i++) {
		for (j = col_start; j <= col_end; j++) {
			bit_sum += bitmap[i][j] - '0';
		}
	}

	/* if all bits are same */
	if (bit_sum == 0 || bit_sum == (row_end - row_start + 1) * (col_end - col_start + 1) ) {
		putchar(bitmap[row_start][col_start]);
		if (++*num_print % ALIGN == 0) {
			putchar('\n');
		}
	}
	/* if all bits are not same */
	else {
		putchar('D');
		if (++*num_print % ALIGN == 0) {
			putchar('\n');
		}
	
		/* calculate the split point of a bitmap */
		row_mid = row_start + (row_end - row_start) / 2;
		col_mid = col_start + (col_end - col_start) / 2;
	
		/* convert top left */
		convert_B_to_D(bitmap, row_start, row_mid, col_start, col_mid, num_print);

		/* convert top right */
		convert_B_to_D(bitmap, row_start, row_mid, col_mid + 1, col_end, num_print);

		/* convert bottom left */
		convert_B_to_D(bitmap, row_mid + 1, row_end, col_start, col_mid, num_print);
		
		/* convert bottom right */
		convert_B_to_D(bitmap, row_mid + 1, row_end, col_mid + 1, col_end, num_print);
	}

	return;
}

void convert_D_to_B(char bitmap[][MAX_DIM], int row_start, int row_end, int col_start, int col_end)
{
	char		ch;
	int  		i, j;
	int  		row_mid, col_mid;

	
	/* check valid bitmap */
	if (row_start > row_end || col_start > col_end) {	
		return;
	}

	/* receive one character */
	while (scanf("%c", &ch) != EOF && ch == '\n') ;
	
	/* check decompostion bit */
	if (ch != 'D') {
		for (i = row_start; i <= row_end; i++) {
			for (j = col_start; j <= col_end; j++) {
				bitmap[i][j] = ch;
			}
		} 	
	}
	else {
		/* calculate the split point of a bitmap */
		row_mid = row_start + (row_end - row_start) / 2;
		col_mid = col_start + (col_end - col_start) / 2;

		/* convert top left */
		convert_D_to_B(bitmap, row_start, row_mid, col_start, col_mid);

		/* convert top right */
		convert_D_to_B(bitmap, row_start, row_mid, col_mid + 1, col_end);

		/* convert bottom left */
		convert_D_to_B(bitmap, row_mid + 1, row_end, col_start, col_mid);
	
		/* convert bottom right */
		convert_D_to_B(bitmap, row_mid + 1, row_end, col_mid + 1, col_end);
	}

	return;
}

int main()
{
	char bitmap[MAX_DIM][MAX_DIM];
	char type, bit_value;
	int  num_rows, num_cols;
	int  i, j;
	int  num_printed_char;


	while (scanf("%c\n", &type) != EOF) {
		/* end of cases */
		if (type == '#') {
			break;
		}
	
		switch (type) {
		/* Type B */
		case 'B':
			/* get # of rows & # of cols */
			scanf("%d %d\n", &num_rows, &num_cols);
			for (i = 0; i < num_rows; i++) {
				for (j = 0; j < num_cols; j++) {
					while (scanf("%c", &bit_value) != EOF && bit_value == '\n') ;
					bitmap[i][j] = bit_value;
				}
			}

			/* convert type-B to type-D */
			printf("D%4d%4d\n", num_rows, num_cols);
			num_printed_char = 0;
			convert_B_to_D(bitmap, 0, num_rows - 1, 0, num_cols - 1, &num_printed_char);
			if (num_printed_char % ALIGN) {
				putchar('\n');
			}

			break;
		/* Type D */
		case 'D':
			/* get # of rows & # of cols */
			scanf("%d %d\n", &num_rows, &num_cols);

			/* convert type-D to type-B */
			printf("B%4d%4d\n", num_rows, num_cols);
			convert_D_to_B(bitmap, 0, num_rows - 1, 0, num_cols - 1);

			/* print bitmap */
			num_printed_char = 0;
			for (i = 0; i < num_rows; i++) {
				for (j = 0; j < num_cols; j++) {
					putchar(bitmap[i][j]);
					if (++num_printed_char % ALIGN == 0) {
						putchar('\n');
					}
				}
			}
			if (num_printed_char % ALIGN) {
				putchar('\n');
			}

			break;
		default:
			break;
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
