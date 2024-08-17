/* @JUDGE_ID: andrea 706 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <string.h>

#define MAX_DIGIT		10
#define	MAX_NUM_LEN		8
#define	MAX_OUTPUT_LEN	200

void make_hor_output(int number, int size, const char* hor_map, char* output, int* pos)
{
	char	sym;
	int		i;

	sym = (hor_map[number] == '1') ? '-' : ' ';

	output[(*pos)++] = ' ';
	for (i = 0; i < size; i++) {
		output[(*pos)++] = sym;
	}	
	output[*pos] = ' ';

	return;
}

void make_ver_output(int number, int size, const char* ver_map[], char* output, int* pos)
{
	char	sym1, sym2;
	int		i;

	sym1 = (ver_map[number][0] == '1') ? '|' : ' ';
	sym2 = (ver_map[number][1] == '1') ? '|' : ' ';

	output[(*pos)++] = sym1;
	for (i = 0; i < size; i++) {
		output[(*pos)++] = ' ';
	}
	output[(*pos)] = sym2;

	return;
}

int main()
{
	const char 	hor_1[MAX_DIGIT] =	{'1', '0', '1', '1', '0', '1', '1', '1', '1', '1'};
	const char* ver_1[MAX_DIGIT] = 	{"11", "01", "01", "01", "11", "10", "10", "01", "11", "11"};
	const char 	hor_2[MAX_DIGIT] =	{'0', '0', '1', '1', '1', '1', '1', '0', '1', '1'};
	const char* ver_2[MAX_DIGIT] = 	{"11", "01", "10", "01", "01", "01", "11", "01", "11", "01"};
	const char 	hor_3[MAX_DIGIT] = 	{'1', '0', '1', '1', '0', '1', '1', '0', '1', '1'};

	int		size;
	char	num_string[MAX_NUM_LEN + 1];
	int		number[MAX_NUM_LEN];
	int		num_digit;
	int		i, pos;
	char	output_hor_1[200], output_hor_2[200], output_hor_3[200];
	char	output_ver_1[200], output_ver_2[200];

	while(scanf("%d %s", &size, num_string) == 2) {
		if (size == 0 && num_string[0] == '0') {
			break;
		} 
		
		/* Init number array */
		num_digit = strlen(num_string);
		for (i = 0; i < num_digit; i++) {
			number[i] = num_string[i] - '0';
		}
		
		/* Make first horizontal output */
		for (pos = 0, i = 0; i < num_digit; i++) {
			make_hor_output(number[i], size, hor_1, output_hor_1, &pos);	
			output_hor_1[++pos] = ' ';
			++pos;
		}
		output_hor_1[pos - 1] = '\0';
	
		/* Make first vertical output */
		for (pos = 0, i = 0; i < num_digit; i++) {
			make_ver_output(number[i], size, ver_1, output_ver_1, &pos);	
			output_ver_1[++pos] = ' ';
			++pos;
		}
		output_ver_1[pos - 1] = '\0';
		
		/* Make second horizontal output */
		for (pos = 0, i = 0; i < num_digit; i++) {
			make_hor_output(number[i], size, hor_2, output_hor_2, &pos);
			output_hor_2[++pos] = ' ';
			++pos;
		} 
		output_hor_2[pos - 1] = '\0';

		/* Make second vertical output */
		for (pos = 0, i = 0; i < num_digit; i++) {
			make_ver_output(number[i], size, ver_2, output_ver_2, &pos);	
			output_ver_2[++pos] = ' ';
			++pos;
		}
		output_ver_2[pos - 1] = '\0';
	
		/* Make third horizontal output */
		for (pos = 0, i = 0; i < num_digit; i++) {
			make_hor_output(number[i], size, hor_3, output_hor_3, &pos);
			output_hor_3[++pos] = ' ';
			++pos;
		} 
		output_hor_3[pos - 1] = '\0';

		/* Output whole line */		
		printf("%s\n", output_hor_1);
		for (i = 0; i < size; i++) {
			printf("%s\n", output_ver_1);
		}
		printf("%s\n", output_hor_2);
		for (i = 0; i < size; i++) {
			printf("%s\n", output_ver_2);
		}
		printf("%s\n", output_hor_3);
		printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
