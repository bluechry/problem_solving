/* @JUDGE_ID: andrea 100 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <limits.h>

int main()
{
	int	l_bound, u_bound;
	int l_bound_org, u_bound_org, temp;
	int i, j, length, max_length;

	while (scanf("%d %d", &l_bound, &u_bound) == 2) {
		l_bound_org = l_bound;
		u_bound_org = u_bound;

		if (u_bound < l_bound) {
			temp = u_bound;
			u_bound = l_bound;
			l_bound = temp;	
		}
		max_length = 0;

		for (i = l_bound; i <= u_bound; i++) {
			length = 1;
			j = i;
			while (j != 1) {
				if (j & 1) {
					j = 3 * j + 1;
					length++;
				}
				else {
					while (!(j & 1)) {
						j >>= 1;
						length++;
					}
				}
			}
			if (max_length < length) 
				max_length = length;
		}

		printf("%d %d %d\n", l_bound_org, u_bound_org, max_length);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
