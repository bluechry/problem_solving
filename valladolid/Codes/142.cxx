/* @JUDGE_ID: andrea 142 C++ "Simulation" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <list>
#include <vector>
#include <cstdio>
#include <cmath>

/*
 * Macros
 */
#define SWAP(x, y) 	((x) ^= (y), (y) ^= (x), (x) ^= (y)	
#define MAX(x, y)  	((x) > (y) ? (x) : (y))					// could be replaced with max(x, y) of <algorithm>
#define MIN(x, y)	((x) < (y) ? (x) : (y))					// could be replaced with min(x, y) of <algorithm>

using namespace std;

typedef struct {
	int		id;	
	int 	x, y;
} Icon;

typedef struct {
	int		id;
	int		x1, y1;
	int		x2, y2;
} Region;

bool check_visible_icon(Icon& i, list<Region>& region_list)
{
	for (list<Region>::iterator r = region_list.begin(); r != region_list.end(); r++) {
		
		if (i.x >= r->x1 && i.x <= r->x2 && i.y >= r->y1 && i.y <= r->y2) {
			return false;
		} 
	}

	return true;
}

int	find_region(int x, int y, list<Region>& region_list)
{
	list<Region>::reverse_iterator r;

	for (r = region_list.rbegin(); r != region_list.rend(); r++) {
		if (x >= r->x1 && x <= r->x2 && y >= r->y1 && y <= r->y2) {
			break;
		}
	}

	if (r != region_list.rend()) {
		return r->id;
	}
	else {
		return -1;
	}	
}

vector<int> find_icon(int x, int y, list<Icon>& icon_list, list<Region>& region_list)
{
	int			min_dist;
	vector<int> min_icon;

	min_dist = 500000;
	list<Icon>::iterator i = icon_list.begin();

	while (i != icon_list.end()) {

		if (check_visible_icon(*i, region_list)) {

			int dist = (x - i->x) * (x - i->x) + (y - i->y) * (y - i->y);
			
			if (dist == min_dist) {
				min_icon.push_back(i->id);
			}
			else if (dist < min_dist) {
				min_dist = dist;
				min_icon.clear();
				min_icon.push_back(i->id);
			}

			i++;
		}
		else {
			i = icon_list.erase(i);
		} 
	}		

	return min_icon;
}

int main()
{
	list<Icon> 		icon_list;
	list<Region> 	region_list; 
	char			cmd;
	int				x1, y1, x2, y2;
	int				region_id, icon_id;

	region_id = 'A';
	icon_id	  = 1;
	while (scanf("%c %d %d %d %d\n", &cmd, &x1, &y1, &x2, &y2) > 0 && cmd != '#') {

		Icon	temp_i;
		Region	temp_r;
		int		found_id;

		switch (cmd) {
		case 'I':
			temp_i.id = icon_id++;
			temp_i.x  = x1;
			temp_i.y  = y1;

			icon_list.push_back(temp_i);
				
			break;
		case 'R':
			temp_r.id = region_id++;
			temp_r.x1 = x1;
			temp_r.y1 = y1;
			temp_r.x2 = x2;
			temp_r.y2 = y2;

			region_list.push_back(temp_r);

			break;
		case 'M':
			// first, find a region
			if ((found_id = find_region(x1, y1, region_list)) > 0) {
				printf("%c\n", found_id);
			}
			// second, find icons
			else {	
				vector<int> result;

				result = find_icon(x1, y1, icon_list, region_list);

				for (vector<int>::iterator i = result.begin(); i != result.end(); i++) {
					printf("%3d", *i);	
				}
				printf("\n");

			}
			break;
		default:
			break;
		}	
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
