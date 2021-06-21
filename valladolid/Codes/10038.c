/* @JUDGE_ID: andrea 10038 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <string.h>

#define MAX_NUM	3000

#define abs(a) ((a) > 0) ? (a) : (-1 * (a))

int main()
{
	int integers[MAX_NUM];
	int check[MAX_NUM];
	int	n_int, n;	
	int i, diff, count;

	while (scanf("%d", &n_int) == 1) {
		for (i = 0; i < n_int; i++) {
			scanf("%d", &n);
			integers[i] = n;
			check[i] = 0;
		}
		
		for (count = 0, i = 0; i < n_int - 1; i++) {
			diff = abs(integers[i] - integers[i + 1]);
			if (!check[diff]) {
				check[diff] = 1;
				count++;
			}
		}
	
		if (count == n_int - 1)
			printf("Jolly\n");
		else 
			printf("Not jolly\n");
	} 
	
	return 0;
}
/* @END_OF_SOURCE_CODE */
