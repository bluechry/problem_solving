/* @JUDGE_ID: andrea 202 C "Arithmatic" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <string.h>

#define MAX 4096

int main()
{
	int nume, denom, quot, remain;
	int check_pos[MAX], dec_place[MAX];
	int count, pos; 
	int i, temp;


	while (scanf("%d %d\n", &nume, &denom) != EOF) {

		memset(&check_pos[0], 0x0, sizeof(int) * MAX);

		/* long division */
		quot = nume / denom;
		remain = nume % denom;

		count = 1;
		while ((pos = check_pos[remain]) == 0) {
			check_pos[remain] = count;
			remain *= 10;
			dec_place[count++] = remain / denom;
			remain %= denom;
		}

		/* Processing Output */
		printf("%d/%d = %d.", nume, denom, quot);

		for (i = 1; i < pos; i++) {
			printf("%d", dec_place[i]);
		}
		
		printf("(");
	
		for (i = pos, temp = 50 + pos; i < count && i < temp; i++) {
			printf("%d", dec_place[i]);			
		}
		if (i == temp) {
			printf("...");
		}
		
		printf(")\n");

		printf("   %d = number of digits in repeating cycle\n", count - pos);
		
		printf("\n");
	}


	return 0;
}
/* @END_OF_SOURCE_CODE */
