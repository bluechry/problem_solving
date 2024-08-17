/* @JUDGE_ID: andrea 10033 C "Simulation" */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>
#include <string.h>

#define NUM_REG		10
#define NUM_WORD	1000

int main()
{
	int 	reg[NUM_REG];
	int		ram[NUM_WORD];
	char 	line[8];
	int		num_case, num_inst, num_exec;
	int		i, pc, word, done;
	int		opcode, arg1, arg2;

	/* Get # of cases */
	gets(line);
	num_case = atoi(line);
	gets(line);

	/* For each cases */
	for (i = 0; i < num_case; i++) {
		/* Init RAM and registers */
		memset(reg, 0x00, NUM_REG  * sizeof(int));
		memset(ram, 0x00, NUM_WORD * sizeof(int));

		/* Get instructions and store them to RAM */
		num_inst = 0;
		while (gets(line) && *line) {
			ram[num_inst++] = atoi(line);
		}

		/* Decode & execute instructions */
		pc = 0;
		num_exec = 0;
		done = 0;
		while (!done) {
			/* decoding */
			word = ram[pc];
			opcode = word / 100;
			arg1 = (word / 10) % 10;
			arg2 = word % 10;
	
			/* execution */	
			num_exec++;
			pc++;

			switch (opcode) {
			case 1:
				done = 1;
				break;
			case 2:
				reg[arg1] = arg2;
				break;		
			case 3:
				reg[arg1] = (reg[arg1] + arg2) % 1000;
				break;		
			case 4:
				reg[arg1] = (reg[arg1] * arg2) % 1000;	
				break;	
			case 5:
				reg[arg1] = reg[arg2];	
				break;	
			case 6:
				reg[arg1] = (reg[arg1] + reg[arg2]) % 1000;	
				break;	
			case 7:
				reg[arg1] = (reg[arg1] * reg[arg2]) % 1000;	
				break;	
			case 8:
				reg[arg1] = ram[reg[arg2]];	
				break;	
			case 9:
				ram[reg[arg2]] = reg[arg1];
				break;	
			case 0:
				if (reg[arg2]) {
					pc = reg[arg1];
				}
				break;
			}
		}
	
		if (i) {
			printf("\n");
		}
		printf("%d\n", num_exec);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
