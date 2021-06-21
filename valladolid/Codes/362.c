/* @JUDGE_ID: andrea 362 C "Simulation" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <stdio.h>
#include <math.h>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>

int main()
{
	long byte_total, byte_remain, byte_acc;
	long time, count;

	count = 0;
	while (scanf("%ld\n", &byte_total) != EOF && byte_total != 0) {

		byte_remain = byte_total;
		byte_acc = 0;
		time = 0;

		printf("Output for data set %ld, %ld bytes:\n", ++count, byte_total);

		while (byte_remain > 0) {
			long byte_trans;
			scanf("%ld\n", &byte_trans);

			byte_remain -= byte_trans;
			byte_acc += byte_trans;

			time++;

			if (time % 5 == 0) {

				if (byte_acc == 0) {
					printf("   Time remaining: stalled\n");
				}
				else {
					double time_remain;
					time_remain = (double)byte_remain / ((double)byte_acc / 5);
				
					printf("   Time remaining: %ld seconds\n", (long)(time_remain + .9999999));

					byte_acc = 0;
				}
			}
		}

		printf("Total time: %ld seconds\n", time);
		printf("\n");
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
