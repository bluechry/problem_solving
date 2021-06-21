/* @JUDGE_ID: andrea 10327 C "Sorting" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

#define SWAP(x, y) \
do { \
	(x) ^= (y); \
	(y) ^= (x); \
	(x) ^= (y); \
} while(0)

int main()
{
	unsigned long 	items[1024], num_items;
	int				i, j;
	int				count;

	while (scanf("%lu\n", &num_items) != EOF) {

		for (i = 0; i < num_items; i++) {
			scanf("%lu", &items[i]);
		}

		count = 0;
		for (i = num_items - 2; i >= 0; i--) {
			for (j = 0; j <= i; j++) {
				if (items[j] > items[j + 1]) {
					SWAP(items[j], items[j + 1]);
					count++;
				}
			}
		}

		printf("Minimum exchange operations : %d\n", count);
	}	

	return 0;		
}

/* @END_OF_SOURCE_CODE */
