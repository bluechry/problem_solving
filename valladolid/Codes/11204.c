/* @JUDGE_ID: andrea 11204 C "Combination" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <string.h>

int main()
{
	int 	num_cases;
	int 	N, M;
	char 	first_choice[64];
	int		choice, num_ways;
	int		i, j;


	scanf("%d\n", &num_cases);

	while (num_cases-- > 0) {

		scanf("%d %d\n", &N, &M);

		memset(first_choice, 0x0, sizeof(char) * 64);	
	
		for (i = 1; i <= M; i++) {
			for (j = 1; j <= N; j++) {
				scanf("%d", &choice);
				if (choice == 1) {
					first_choice[j]++;
				}
			}
		}		

		num_ways = 1;		
		for (j = 1; j <= N; j++) {
			if (first_choice[j] > 1) {
				num_ways *= first_choice[j];
			}
		}

		printf("%d\n", num_ways);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
