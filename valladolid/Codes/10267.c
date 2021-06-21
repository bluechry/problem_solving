/* @JUDGE_ID: andrea 10267 C " " */
/* @BEGIN_OF_SOURCE_CODE */
#include <stdio.h>

#define MAX_M_N 	250
#define NUM_DIREC 	4	

static char bitmap[MAX_M_N + 1][MAX_M_N + 1];
const int   direction_i[NUM_DIREC] = { 0, -1, 0, 1}; 
const int   direction_j[NUM_DIREC] = {-1,  0, 1, 0}; 

void fill(int i, int j, char cur_color, char color)
{
    int k;
    int next_i, next_j;

    bitmap[i][j] = color;

    for (k = 0; k < NUM_DIREC; k++) {
        next_i = i + direction_i[k];
        next_j = j + direction_j[k];

        if (bitmap[next_i][next_j] == cur_color) {
            fill(next_i, next_j, cur_color, color);
        }   
    }   
    
    return;
}

int main()
{
	int m, n;	
	int i, i1, i2, j, j1, j2, temp;
	char command, color;
	char filename[13];

	while (scanf("%c", &command) && command != 'X') {
		switch (command) {
		case 'I':
			scanf("%d %d", &m, &n);
		case 'C':
			for (i = 1; i <= n; i++) {
				for (j = 1; j <= m; j++) {
					bitmap[i][j] = 'O';
				}
			}
			break;
		case 'L':
			scanf("%d %d %c", &j, &i, &color);
			bitmap[i][j] = color;
			break;
		case 'V':
			scanf("%d %d %d %c", &j, &i1, &i2, &color);
			if (i1 > i2) {
				temp =  i1; i1 = i2; i2 = temp;
			}
			for (i = i1; i <= i2; i++) {
				bitmap[i][j] = color;
			}
			break;
		case 'H':
			scanf("%d %d %d %c", &j1, &j2, &i, &color);
			if (j1 > j2) {
				temp = j1; j1 = j2; j2 = temp;
			}
			for (j = j1; j <= j2; j++) {
				bitmap[i][j] = color;
			}
			break;
		case 'K':
			scanf("%d %d %d %d %c", &j1, &i1, &j2, &i2, &color);
			for (i = i1; i <= i2; i++) {
				for (j = j1; j <= j2; j++) {
					bitmap[i][j] = color;
				}
			}
			break;
		case 'F':
			scanf("%d %d %c", &j, &i, &color);
			if (color != bitmap[i][j]) {
				fill(i, j, bitmap[i][j], color);
			}
			break;
		case 'S':
			scanf("%s", filename);
			puts(filename);
			for (i = 1; i <= n; i++) {
				for (j = 1; j <= m; j++) {
					putchar(bitmap[i][j]);
				}
				putchar('\n');
			}
			break;	
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
