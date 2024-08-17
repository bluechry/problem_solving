/* @JUDGE_ID: andrea 541 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <string.h>

int main()
{
	int row_sum[100], col_sum[100];
	int num;
	int mat_size;
	int i, j, error_row, error_col, is_corrupt; 

	while (scanf("%d\n", &mat_size) != EOF & mat_size != 0) {

		/* init row_sum[] & col_sum[] */
		memset(&row_sum[0], 0x0, sizeof(int) * 100);
		memset(&col_sum[0], 0x0, sizeof(int) * 100);

		/* calculate row_sum & col_sum */
		for (i = 0; i < mat_size; i++) {

			for (j = 0; j < mat_size; j++) {
				
				scanf("%d\n", &num);

				row_sum[i] += num;
				col_sum[j] += num;
			}
		}

		/* check row_sum is valid */
		is_corrupt = 0;
		error_row = error_col = -1;
		for (i = 0; i < mat_size; i++) {

			if (row_sum[i] & 0x1) {
				if (error_row >= 0) {
					is_corrupt = 1;
					break;
				}
				error_row = i;
			}

			if (col_sum[i] & 0x1) {
				if (error_col >= 0) {
					is_corrupt = 1;
					break;
				}
				error_col = i;
			}
		}

		/* output result */
		if (is_corrupt) {
			printf("Corrupt\n");
		}
		else if (error_col < 0 && error_col < 0) {
			printf("OK\n");
		}
		else {
			printf("Change bit (%d,%d)\n", ++error_row, ++error_col);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
