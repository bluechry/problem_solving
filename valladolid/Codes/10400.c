/* @JUDGE_ID: andrea 10400 C "Bruteforce" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <string.h>

#define MAX_OP	101
#define MAX_VAL	64001

char history[MAX_OP][MAX_VAL];

int find_expression(int numbers[], int pos_num, int num_ops, char operators[], int pos_ops, int cur_value, int target)
{
	int 	idx_n, idx_o;
	char 	ops[] = "+-*/";
	int 	next_value;	
	int		i;

	if ( cur_value > 32000 || cur_value < -32000) { 
		return 0;
	}
	if (history[num_ops][cur_value + 32000]) {
		return 0;
	}

	if (num_ops == 0) {
		operators[pos_ops] = '\0';

		if (cur_value == target) {
			
			for (idx_n = 0, idx_o = 0; operators[idx_o] != '\0'; idx_n++, idx_o++) {
				printf("%d%c", numbers[idx_n], operators[idx_o]);
			}
			printf("%d=%d\n", numbers[idx_n], target);

			return 1;
		}
		else {
			history[num_ops][cur_value + 32000] = 1;

			return 0;
		}
	}

	for (i = 0; ops[i] != '\0'; i++) {
		switch (ops[i]) {
		case '+':
			next_value = cur_value + numbers[pos_num];
			break;
		case '-':
			next_value = cur_value - numbers[pos_num];
			break;
		case '*':
			next_value = cur_value * numbers[pos_num];
			break;
		case '/':
			if (cur_value % numbers[pos_num] != 0) {
				continue;	
			}
			next_value = cur_value / numbers[pos_num];
			break;
		}

		operators[pos_ops] = ops[i];

		if (find_expression(numbers, pos_num + 1, num_ops - 1, operators, pos_ops + 1, next_value, target) == 1) {
			return 1;	
		}
	}

	history[num_ops][cur_value + 32000] = 1;

	return 0;
}

int main()
{
	int 	num_cases, p;
	int 	numbers[128];
	char 	operators[128];
	int		target;
	int 	i, num_ops;

	scanf("%d\n", &num_cases);
	while (num_cases-- > 0) {
		scanf("%d", &p);

		for (i = 0; i < p; i++) {
			scanf("%d", &numbers[i]);
		}

		scanf("%d\n", &target);

		memset(&history[0][0], 0x0, sizeof(char) * MAX_OP * MAX_VAL);

		num_ops = p - 1;
		if (find_expression(numbers, 1, num_ops, operators, 0, numbers[0], target) == 0) {
			printf("NO EXPRESSION\n");
		}
	}	

	return 0;
}
/* @END_OF_SOURCE_CODE */
