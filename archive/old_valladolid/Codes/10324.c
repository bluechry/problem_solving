/* @JUDGE_ID: andrea ##### C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>

#define SWAP(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))

int check_sequence(int change_pos[], int num_change_pos, int start, int end)
{
	int i;

	for (i = 0; i < num_change_pos; i++) {
		if (change_pos[i] > end) {
			break;
		} 
		else if (change_pos[i] > start && change_pos[i] <= end) {
			return 0;
		}
	}

	return 1;
}

int main()
{
	char	line[1000001];
	int 	change_pos[1000001], num_change_pos;
	int		start, end;
	int		num_tests, case_id, i;

	case_id = 0;
	while (gets(line) != NULL && line[0] != '\n') {

		/* find positions that a character is changed */
		change_pos[0] = 0;
		num_change_pos = 1;

		for (i = 1; line[i] != '\0'; i++) {
			if (line[i] != line[i - 1]) {
				change_pos[num_change_pos++] = i; 
			}
		}

		/* input processing */
		printf("Case %d:\n", ++case_id);
	
		scanf("%d\n", &num_tests);
		for (i = 0; i < num_tests; i++) {
			scanf("%d %d\n", &start, &end);
			if (start > end) SWAP(start, end);
			
			if (check_sequence(change_pos, num_change_pos, start, end)) {
				puts("Yes");
			}
			else {
				puts("No");
			}
		}
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
