/* @JUDGE_ID: andrea 299 C "Sorting" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

#define SWAP(_a, _b) \
do { \
	int temp; \
	temp = _a; \
	_a = _b; \
	_b = temp; \
} while(0)

int main()
{
	int num_cases, num_elems;
	int num[64];
	int i, j;
	int count;

	scanf("%d\n", &num_cases);

	while (num_cases-- > 0) {

		scanf("%d\n", &num_elems);

		for (i = 0; i < num_elems; i++) {
			scanf("%d", &num[i]);
		}

		count = 0;
		for (i = 1; i < num_elems; i++) {
			for (j = 0; j < num_elems - i; j++) {
				if (num[j] > num[j + 1]) {
					SWAP(num[j], num[j + 1]);
					count++;
				}
			}
		}	
		
		printf("Optimal train swapping takes %d swaps.\n", count);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
