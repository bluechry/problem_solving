/* @JUDGE_ID: andrea 591 C "Arithmatics" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <math.h>

int main()
{
	int 	num_stack;
	int		stack[64];
	int		count, i;
	int 	avr, num_move;

	count = 1;
	while (scanf("%d\n", &num_stack) != EOF && num_stack != 0) {
		for (avr = 0, i = 0; i < num_stack; i++) {
			scanf("%d", &stack[i]);
			avr += stack[i];
		}
		avr /= num_stack;

		num_move = 0;
		for (i = 0; i < num_stack; i++) {
			num_move += abs(avr - stack[i]);
		}
		num_move /= 2;

		printf("Set #%d\n", count);
		printf("The minimum number of moves is %d.\n", num_move);
		printf("\n");

		count++;
	}


	return 0;
}
/* @END_OF_SOURCE_CODE */
