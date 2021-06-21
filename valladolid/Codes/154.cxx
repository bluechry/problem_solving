/* @JUDGE_ID: andrea 154 C++ "Simulation" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <vector>
#include <cstdio>
#include <climits>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>

using namespace std;

typedef struct {
	char r, o, y, g, b;
} Recycle;

void read_input(char line[], Recycle* rec)
{
	char* ptr;

	for (ptr = &line[0]; *ptr != '\0'; ptr++) {
		switch (*ptr) {
		case 'r':
			rec->r = *(ptr += 2); 
			break;
		case 'o':
			rec->o = *(ptr += 2); 
			break;
		case 'y':
			rec->y = *(ptr += 2); 
			break;
		case 'g':
			rec->g = *(ptr += 2); 
			break;
		case 'b':
			rec->b = *(ptr += 2); 
			break;
		default:
			break;
		}
	}

	return;
} 

int find_min_changes(vector<Recycle>& vec_rec)
{
	int i, j;
	int min_diff = INT_MAX, min_pos = 0; 

	for (i = 0; i < vec_rec.size(); i++) {
		int diff_sum = 0;
		for (j = 0; j < vec_rec.size(); j++) {
			int diff = 0;

			if (vec_rec[i].r != vec_rec[j].r) diff++;
			if (vec_rec[i].o != vec_rec[j].o) diff++;
			if (vec_rec[i].y != vec_rec[j].y) diff++;
			if (vec_rec[i].g != vec_rec[j].g) diff++;
			if (vec_rec[i].b != vec_rec[j].b) diff++;
		
			diff_sum += diff;	
		}

		if (min_diff > diff_sum) {
			min_diff = diff_sum;
			min_pos = i;
		}
	}

	return min_pos + 1;
}

int main()
{
	char				line[512];
	vector<Recycle> 	vec_rec;

	vec_rec.reserve(128);

	// Read Input
	while (gets(line) != NULL && line[0] != '#') {

		// End of a Block, Calc and Print a Result
		if (line[0] == 'e') {
			if (vec_rec.size() > 0) { 
				int result = find_min_changes(vec_rec);

				cout << result << endl;

				vec_rec.clear();
			}
		}
		// Parse a Line
		else {
			Recycle temp;

			read_input(line, &temp);
			
			vec_rec.push_back(temp);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
