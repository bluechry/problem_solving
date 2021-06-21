/* @JUDGE_ID: andrea 11530 C "Ad Hoc" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <stdio.h>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define MAX(x, y)  	((x) > (y) ? (x) : (y))
#define MIN(x, y)	((x) < (y) ? (x) : (y))

int main()
{
	int 	num_cases, i, count;
	int		key_press[26] = {            1, 2, 3,  1, 2, 3, 
							  1, 2, 3,   1, 2, 3,  1, 2, 3, 
							 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
	char	line[128], *ptr;

	fgets(line, 128, stdin);
	sscanf(line, "%d\n", &num_cases);

	for (i = 1; i <= num_cases; i++) {
		fgets(line, 128, stdin);
		count = 0;
		for (ptr = &line[0]; *ptr != '\n'; ptr++) {
			switch (*ptr) {
			case ' ':
				count++;
				break;
			default:
				count += key_press[*ptr - 'a']; 
				break;
			}
		}
		
		printf("Case #%d: %d\n", i, count);
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
