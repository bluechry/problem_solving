/* @JUDGE_ID: andrea 10252 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <string.h>

#define MAX_LEN_STRING	1000
#define NUM_ALPHA		26
#define MIN(a, b) ((a) > (b)) ? (b) : (a)

int main()
{
	char 	arg1[MAX_LEN_STRING], arg2[MAX_LEN_STRING];
	int		alpha_stat_arg1[NUM_ALPHA], alpha_stat_arg2[NUM_ALPHA];
	int		len_arg1, len_arg2;
	int		i, j, count;
	char 	ch;

	while (gets(arg1) && gets(arg2)) {
		memset(alpha_stat_arg1, 0x00, sizeof(int) * NUM_ALPHA);
		memset(alpha_stat_arg2, 0x00, sizeof(int) * NUM_ALPHA);

		len_arg1 = strlen(arg1);
		len_arg2 = strlen(arg2);
		
		for (i = 0; i < len_arg1; i++) {
			ch = arg1[i];
			alpha_stat_arg1[ch - 'a']++;
		}

		for (i = 0; i < len_arg2; i++) {
			ch = arg2[i];
			alpha_stat_arg2[ch - 'a']++;
		}

		for (i = 0; i < NUM_ALPHA; i++) {
			if (alpha_stat_arg1[i] && alpha_stat_arg2[i]) {
				count = MIN(alpha_stat_arg1[i], alpha_stat_arg2[i]);
				for (j = 0; j < count; j++) {
					putchar(i + 'a');
				}
			}		
		}
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
