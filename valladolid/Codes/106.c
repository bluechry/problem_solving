/* @JUDGE_ID: andrea 106 C "Number Theory" */
/* @BEGIN_OF_SOURCE_CODE */

#include <stdio.h>
#include <string.h>
#include <math.h>

int calculate_gcd(int a, int b)
{
	int temp;

	if (b > a) {
		a ^= b;
		b ^= a;
		a ^= b;
	}

	while (b > 0) {
		temp = a;
		a = b;
		b = temp % b;
	}

	return a;
}

int main()
{
	int 	n, temp, i;
	int 	r, s;
	int 	x, y, z;
	char	check[1000001];
	int		num_triple, num_no_triple;	

	while (scanf("%d\n", &n) != EOF) {

		memset(&check[0], 0x0, sizeof(char) * (n + 1));	

		temp = sqrt(n);

		num_triple = 0;
		for (s = 1; s <= temp; s++) {
			for (r = s + 1; r <= temp; r++) {
				
				if (((r & 0x1) == 0x1 && (s & 0x1) == 0x1) || calculate_gcd(r, s) != 1) {
					continue;
				}

				x = r * r - s * s;	
				y = 2 * r * s;
				z = r * r + s * s;

				if (z <= n) {
					num_triple++;

					for (i = 1; z * i <= n; i++) {
						check[x * i] = check[y * i] = check[z * i] = 1;
					}
				}
			}
		}

		num_no_triple = 0;
		for (i = 1; i <= n; i++) {
			if (check[i] == 0) {
				num_no_triple++;
			}	
		}

		printf("%d %d\n", num_triple, num_no_triple);
	}	

	return 0;
}
/* @END_OF_SOURCE_CODE */
