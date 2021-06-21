/* @JUDGE_ID: andrea 264 C "arithmetic" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <math.h>

int main()
{
	int i;
	int nume, denom;
	int group, pos;

	while (scanf("%d\n", &i) != EOF) {

		group = (-1.0 + sqrt(1.0 + 8.0 * (double)i)) / 2.0;	
		
		pos = i - (group * (group + 1) / 2);

		if (pos > 0) {
			group++;
		}
		else {
			pos = group;
		}

		if (group & 0x1) {
			nume = group + 1 - pos;
			denom = pos;
		}
		else {
			nume = pos;
			denom = group + 1 - pos;
		}

		printf("TERM %d IS %d/%d\n", i, nume, denom);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
