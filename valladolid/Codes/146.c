/* @JUDGE_ID: andrea 146 C "Recursive Call" */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <string.h>

#define MAX_SEQ		50
#define	NUM_ALPHA 	26

int main()
{

	char	seq[MAX_SEQ + 1];
	int		alpha_count[NUM_ALPHA];
	int		len_seq, max_alpha;
	int		i, j, flag;
	int		alpha_off, digit;

	while (scanf("%s", seq) == 1) {
		if (strcmp(seq, "#") == 0) {
			break;
		}

		/* Init count of each alphabet */
		len_seq = strlen(seq);
		memset(alpha_count, 0, NUM_ALPHA * sizeof(int));

		for (max_alpha = 0, i = 0; i < len_seq; i++) {
			if (seq[i] > max_alpha)	{
				max_alpha = seq[i];
			}
		}
		max_alpha -= 'a';
	
		/* Find first digit which should be changed */
		for (i = len_seq - 1; i >= 0; i--) {
			alpha_off = seq[i] - 'a';
			alpha_count[alpha_off]++;

			flag = 0;
			for (++alpha_off; alpha_off <= max_alpha; alpha_off++) {
				if (alpha_count[alpha_off] > 0) {
					flag = 1;
					break; 
				}
			}
			if (flag) break;
		}
		digit = i;

		/* Make next sequence */
		if (digit < 0) {
			printf("No Successor\n");
		}
		else {
			seq[digit++] = alpha_off + 'a';
			alpha_count[alpha_off]--;
			for (i = 0; i <= max_alpha; i++) {
				if (alpha_count[i] != 0) {
					for (j = 0; j < alpha_count[i]; j++) {
						seq[digit++] = i + 'a';
					}	
				}
			}
			seq[digit] = '\0';
			printf("%s\n", seq);	
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
