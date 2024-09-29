/* @JUDGE_ID: andrea 10281 C "Simple Iteration" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <stdio.h>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define MAX(x, y)  	((x) > (y) ? (x) : (y))
#define MIN(x, y)	((x) < (y) ? (x) : (y))

int main()
{
	int 	hh, mm, ss;
	int 	cur_time, last_time;
	int		cur_speed, last_speed;
	double	cur_distance, last_distance;
	char	line[128];

	last_time = last_speed = 0;
	last_distance = 0.0;	

	while (fgets(line, 128, stdin) != NULL) {

		if (sscanf(line, "%2d:%2d:%2d %d\n", &hh, &mm, &ss, &cur_speed) == 4) {
			cur_time = 3600 * hh + 60 * mm + ss;
			cur_distance = last_distance + (cur_time - last_time) * last_speed / 3600.0;

			last_distance = cur_distance;
			last_speed = cur_speed;
			last_time = cur_time;
		}
		else {
			cur_time = 3600 * hh + 60 * mm + ss;
			cur_distance = last_distance + (cur_time - last_time) * last_speed / 3600.0;

			printf("%.2d:%.2d:%.2d %.2lf km\n", hh, mm, ss, cur_distance);
		}
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
