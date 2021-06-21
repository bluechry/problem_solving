/* @JUDGE_ID: andrea 11192 C "String" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <stdio.h>
#include <string.h>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define MAX(x, y)  	((x) > (y) ? (x) : (y))
#define MIN(x, y)	((x) < (y) ? (x) : (y))

void reverse_string(char* h, char* t)
{
	while (h < t) {
		SWAP(*h, *t);
		++h;
		--t;
	}
}

int main()
{
	int		num_grp, unit;
	char	line[128];
	char*	ptr;

	while (fgets(line, 128, stdin) != NULL && line[0] != '0') {
		
		sscanf(line, "%d %s\n", &num_grp, line);

		unit = strlen(line) / num_grp;
		for (ptr = &line[0]; *ptr != '\0'; ptr += unit) {
			reverse_string(ptr, ptr + unit - 1);
		}

		printf("%s\n", line);
	}	

	return 0;		
}

/* @END_OF_SOURCE_CODE */
