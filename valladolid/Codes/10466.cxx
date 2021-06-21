#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	double pi;
	pi = 2.0 * acos(0.0);

	int 	n;
	double 	T;
	while (scanf("%d %lf\n", &n, &T) != EOF) {

		double x, y;
		x = y = 0.0;

		for (int i = 0; i < n; i++) {
			double r, t;
			scanf("%lf %lf\n", &r, &t);

			double a;
			a = (2 * pi / t) * T;

			x = x + r * cos(a);
			y = y + r * sin(a);

			double d;
			d = sqrt(x * x + y * y);

			if (i > 0) {
				printf(" %.4lf", d);
			}
			else {
				printf("%.4f", d);
			}
		}
		printf("\n");
	}

	return 0;
}
