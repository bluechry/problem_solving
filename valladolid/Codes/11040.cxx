/* @JUDGE_ID: andrea 11040 C++ "Ad Hoc" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int num_cases;
	int matrix[10][10];

	scanf("%d\n", &num_cases);
	while (num_cases-- > 0) {

		scanf("%d\n", &matrix[1][1]);
		scanf("%d %d\n", &matrix[3][1], &matrix[3][3]);
		scanf("%d %d %d\n", &matrix[5][1], &matrix[5][3], &matrix[5][5]);
		scanf("%d %d %d %d\n", &matrix[7][1], &matrix[7][3], &matrix[7][5], &matrix[7][7]);
		scanf("%d %d %d %d %d\n", &matrix[9][1], &matrix[9][3], &matrix[9][5], &matrix[9][7], &matrix[9][9]);

		matrix[9][2] = (matrix[7][1] - matrix[9][1] - matrix[9][3]) / 2;
		matrix[9][4] = (matrix[7][3] - matrix[9][3] - matrix[9][5]) / 2;
		matrix[9][6] = (matrix[7][5] - matrix[9][5] - matrix[9][7]) / 2;
		matrix[9][8] = (matrix[7][7] - matrix[9][7] - matrix[9][9]) / 2;

		int i, j;
		for (i = 8; i >= 1; i--) {
			for (j = 1; j <= i; j++) {
				matrix[i][j] = matrix[i + 1][j] + matrix[i + 1][j + 1];
			}
		}	

		for (i = 1; i <= 9; i++) {
			printf("%d", matrix[i][1]);
			for (j = 2; j <= i; j++) {
				printf(" %d", matrix[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
