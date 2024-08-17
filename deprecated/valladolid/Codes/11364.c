/* @JUDGE_ID: andrea 11364 C "Ad Hoc" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

int main()
{
	int num_cases, num_items;
	int i, item[32];
	int min, max;

	scanf("%d\n", &num_cases);
	while (num_cases-- > 0) {

		scanf("%d\n", &num_items);
		for (i = 0; i < num_items; i++) {
			scanf("%d", &item[i]);	
		}

		min = 100, max = 0;
		for (i = 0; i < num_items; i++) {
			if (min > item[i]) min = item[i];
			if (max < item[i]) max = item[i];
		}

		printf("%d\n", 2 * (max - min));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
