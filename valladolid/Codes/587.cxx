/* @JUDGE_ID: andrea 587 C++ "Simulation" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>

using namespace std;

void find_treasure(char map[])
{
	char*	ptr = &map[0];
	double	x, y;

	x = y = 0.0;
	while (*ptr != '.') {
		int	num_walks;

		// skip nondigits
		while (!isdigit(*ptr)) ++ptr;
	
		// read # of walks	
		num_walks = atoi(ptr);

		// skip nonalphabet
		while (!isalpha(*ptr)) ++ptr;

		// read a direction
		switch (*ptr) {
		case 'N':
			++ptr;
			if (*ptr == 'E') {
				double temp = (sqrt(2.0) * num_walks) / 2.0;

				x += temp;
				y += temp;
			}
			else if (*ptr == 'W') {
				double temp = (sqrt(2.0) * num_walks) / 2.0;

				x -= temp;
				y += temp;	
			}
			else {
				y += num_walks;
			}
			break;
		case 'E':
			x += num_walks;
			break;
		case 'S':
			++ptr;
			if (*ptr == 'E') {
				double temp = (sqrt(2.0) * num_walks) / 2.0;
				
				x += temp;
				y -= temp;
			}
			else if (*ptr == 'W') {
				double temp = (sqrt(2.0) * num_walks) / 2.0;
				
				x -= temp;
				y -= temp;				
			}
			else {
				y -= num_walks;
			}
			break;
		case 'W':
			x -= num_walks;
			break; 
		default:
			break;
		}			
	
		// skip chars util ',' or '.'
		while (*ptr != ',' && *ptr != '.') ++ptr; 		
	}

	printf("The treasure is located at (%.3lf,%.3lf).\n", x, y);
	printf("The distance to the treasure is %.3lf.\n", sqrt(x * x + y * y));

	return;
}

int main()
{

	char 	line[512];
	double 	x, y;
	int 	count;

	count = 1;
	while (gets(line) != NULL) {

		if (!strcmp(line, "END")) {
			break;
		}

		printf("Map #%d\n", count++);
		find_treasure(line);
		printf("\n");
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
