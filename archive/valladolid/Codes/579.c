/* @JUDGE_ID: andrea 579 C "Ad Hoc" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <math.h>

int main()
{
	int 	hour, minute;
	double	ang_hour, ang_minute; 
	double	diff;	

	while(scanf("%d:%2d\n", &hour, &minute) != EOF) {
		if (hour == 0.00 && minute == 0.00) break;
		
		ang_hour = 30.00 * hour + 0.50 * minute;
		ang_minute = 6.0 * minute;

		diff = fabs(ang_hour - ang_minute);
		diff = (diff > 180.00) ? 360.00 - diff : diff;

		printf("%0.3lf\n", diff);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
