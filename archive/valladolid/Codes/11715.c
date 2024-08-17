/* @JUDGE_ID: andrea 11715 C "Arithmatic & Algebra" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <math.h>

int main()
{
	double	u, a, t, v, s;
	int		case_id, count;

	count = 0;
	while (scanf("%d\n", &case_id) != EOF && case_id != 0) {

		switch (case_id) {

		case 1:
			scanf("%lf %lf %lf\n", &u, &v, &t);

			a = (v - u) / t;
			s = (u + v) / 2 * t;

			printf("Case %d: %0.3lf %0.3lf\n", ++count, s, a);

			break;
		case 2:
			scanf("%lf %lf %lf\n", &u, &v, &a);

			t = (v - u) / a;
			s = (u + v) / 2 * t;

			printf("Case %d: %0.3lf %0.3lf\n", ++count, s, t);
			
			break;
		case 3:
			scanf("%lf %lf %lf\n", &u, &a, &s);

			t = (-u + sqrt(u * u + 2 * a * s)) / a; 
			v = u + a * t;

			printf("Case %d: %0.3lf %0.3lf\n", ++count, v, t);
			
			break;
		case 4:
			scanf("%lf %lf %lf\n", &v, &a, &s);

			t = (-v + sqrt(v * v - 2 * a * s)) / -a; 
			u = v - a * t;

			printf("Case %d: %0.3lf %0.3lf\n", ++count, u, t);
			
			break;
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
