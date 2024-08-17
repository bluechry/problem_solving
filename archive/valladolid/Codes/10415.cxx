/* @JUDGE_ID: andrea 10415 C++ "Simlulation" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <cstdio>
#include <cstring>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>
#define ABS(x)		((x) < 0 ? -1 * (x) : (x))

#define x_b	 	(0x1 << 2)
#define x_a	 	x_b | (0x1 << 3)
#define x_g	 	x_a | (0x1 << 4)
#define x_f	 	x_g | (0x1 << 7)
#define x_e	 	x_f | (0x1 << 8)
#define x_d	 	x_e | (0x1 << 9)
#define x_c	 	x_d | (0x1 << 10)

#define X_C  	(0x1 << 3)
#define X_B		(0x1 << 1) | (0x1 << 2)
#define X_A	 	X_B | (0x1 << 3)
#define X_G		X_A | (0x1 << 4)
#define X_F		X_G | (0x1 << 7)
#define X_E		X_F | (0x1 << 8)
#define X_D		X_E | (0x1 << 9)

using namespace std;

void count_press(char line[], char count[])
{
	char* 	ptr;
	int 	prev, curr;

	ptr = &line[0];
	prev = 0;
	while (*ptr != '\n') {

		switch (*ptr) {
		case 'c':
			curr = x_c;
			break;
		case 'd':
			curr = x_d;
			break;
		case 'e':
			curr = x_e;
			break;
		case 'f':
			curr = x_f;
			break;
		case 'g':
			curr = x_g;
			break;
		case 'a':
			curr = x_a;
			break;
		case 'b':
			curr = x_b;
			break;
		case 'C':
			curr = X_C;
			break;
		case 'D':
			curr = X_D;
			break;
		case 'E':
			curr = X_E;
			break;
		case 'F':
			curr = X_F;
			break;
		case 'G':
			curr = X_G;
			break;
		case 'A':
			curr = X_A;
			break;
		case 'B':
			curr = X_B;
			break;
		default:
			break;
		}	

		int mask = 0x1;
		for (int i = 1; i <= 10; i++) {
			mask <<= 1;
			if (!(prev & mask) && (curr & mask)) {
				count[i]++;
			}
		}

		prev = curr;
		ptr++;
	}	

	return;
}

int main()
{
	int n;

	scanf("%d\n", &n);

	while (n-- > 0) {
		char line[256];
		char count[16];
		
		fgets(line, 256, stdin);

		memset(&count[0], 0x0, sizeof(char) * 16);

		count_press(line, count);	

		int i;
		for (i = 1; i < 10; i++) {
			printf("%d ", count[i]);
		}
		printf("%d\n", count[i]);
	}	

	return 0;		
}

/* @END_OF_SOURCE_CODE */
