/* @JUDGE_ID: andrea 107 C "Bruteforce" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <math.h>

int main()
{
	int H, Nw;
	int N, d;
	int height, num_worker;
	int	num_cats, stack_height; 
	int found;

	while (scanf("%d %d\n", &H, &Nw) != EOF && H != 0 && Nw != 0) {

		if (H == 1) {
			printf("%d %d\n", 0, 1);
			continue;
		}

		/* Find the values of N & d */
		found = 0;
		for (N = 1; ; N++) {
			height = num_worker = 1;
			for (d = 1; ; d++) {
				height *= (N + 1);
				num_worker *= N;	

				if (height > H || num_worker > Nw) {
					break;
				}

				if (height == H && num_worker == Nw) {
					found = 1;
					break;
				}
			}
	
			if (found == 1) {
				break;
			}
		}	

		/* Calculate # of cats that are not working & the height of the stack */ 
		num_cats 	 = (N == 1) ? d : (pow(N, d) - 1) / (N - 1);
		stack_height = pow(N + 1, d + 1) - pow(N, d + 1);

		printf("%d %d\n", num_cats, stack_height);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
