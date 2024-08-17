/* @JUDGE_ID: andrea 10107 C "Mathematics" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

#define SWAP(_x, _y) ((_x) ^= (_y), (_y) ^= (_x), (_x) ^= (_y))

int main()
{
	int num, num_array[10000];
	int num_elems;
	int median, i;

	num_elems = 0;
	while (scanf("%d\n", &num) != EOF) {

		/* Store one integer into an ordered list */	
		num_array[num_elems++] = num;

		for (i = num_elems - 1; i >= 0; i--) {
			if (num_array[i] < num_array[i - 1]) {
				SWAP(num_array[i], num_array[i - 1]);
			}
			else {
				break;
			}
		}

		/* Find a median */
		if (num_elems & 0x1) {
			median = num_array[num_elems / 2];
		}
		else {
			median = (num_array[num_elems / 2 - 1] + num_array[num_elems / 2]) / 2;
		}

		printf("%d\n", median);
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
