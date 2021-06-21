/* @JUDGE_ID: andrea 275 C "Arithmatic" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <string.h>

int main()
{
	int nume, denom;
	int remain, check_remain[4096], pos;
	int dec_place[4096]; 
	int i, count, num_char;

	while (scanf("%d %d\n", &nume, &denom) != EOF) {
		
		if (nume == 0 && denom == 0) {
			break;
		}
	
		memset(&check_remain[0], 0x0, sizeof(int) * 4096);


		/* processing long division */	
		remain = nume % denom;
		count = 1;
		while (remain != 0 && (pos = check_remain[remain]) == 0) {
			
			check_remain[remain] = count;
			remain *= 10;
			dec_place[count++] = remain / denom;
			remain %= denom; 
		}
	
	
		/* processing output */
		printf(".");
		for (num_char = 1, i = 1; i < count; i++) {
			printf("%d", dec_place[i]);

			if (++num_char % 50 == 0) {
				printf("\n");
			}
		}

		if (num_char % 50 != 0) {
			printf("\n");
		}

		if (remain == 0) {
			printf("This expansion terminates.\n");	
			printf("\n");
		}
		else {
			printf("The last %d digits repeat forever.\n", count - pos);
			printf("\n");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
