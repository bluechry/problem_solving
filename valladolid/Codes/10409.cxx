/* @JUDGE_ID: andrea 10409 C++ "Simlulation" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <cstdio>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>
#define ABS(x)		((x) < 0 ? -1 * (x) : (x))

using namespace std;

int main()
{
	int n;

	while (scanf("%d\n", &n) != EOF && n != 0) {
		
		int  v[4] 	= {2, 1, 5, 6};
		int  h[4] 	= {3, 1, 4, 6};
		int  v_top_pos	= 1;
		int  h_top_pos 	= 1;		
		char line[8];
	
		for (int i = 0; i < n; i++) {

			fgets(line, 8, stdin);

			switch (line[0]) {
			case 'n':
				v_top_pos 	 = (v_top_pos + 1) % 4;
				h[h_top_pos] = v[v_top_pos];
				h[(h_top_pos + 2) % 4] = 7 - h[h_top_pos];
				break;	
			case 's':
				v_top_pos	 = (v_top_pos + 3) % 4;
				h[h_top_pos] = v[v_top_pos];
				h[(h_top_pos + 2) % 4] = 7 - h[h_top_pos];
				break;
			case 'w':
				h_top_pos 	 = (h_top_pos + 1) % 4;
				v[v_top_pos] = h[h_top_pos];
				v[(v_top_pos + 2) % 4] = 7 - v[v_top_pos];
				break;
			case 'e':
				h_top_pos 	 = (h_top_pos + 3) % 4;
				v[v_top_pos] = h[h_top_pos];
				v[(v_top_pos + 2) % 4] = 7 - v[v_top_pos];
				break;
			default:
				break;
			}
		}

		printf("%d\n", v[v_top_pos]);	
	}
	
	return 0;		
}

/* @END_OF_SOURCE_CODE */
