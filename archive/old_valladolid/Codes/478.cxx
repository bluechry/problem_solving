/* @JUDGE_ID: andrea 478 C++ "Geometry" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
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
	char	shape_id;
	double	val[6];
} Shape;	

bool check_rectangle(double x, double y, Shape& shape)
{
	double x1, y1, x2, y2;

	x1 = shape.val[0];
	y1 = shape.val[1];
	x2 = shape.val[2];
	y2 = shape.val[3];

	if (x > x1 && x < x2 && y < y1 && y > y2) {
		return true;
	}

	return false;	
}

bool check_circle(double x, double y, Shape& shape)
{
	double x1, y1, r;
	double dist;

	x1 = shape.val[0];
	y1 = shape.val[1];
	r  = shape.val[2];

	dist = (x - x1) * (x - x1) + (y - y1) * (y - y1);

	if (dist < r * r) {
		return true;
	}	

	return false;
}

double calculate_area(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double area;

	area = fabs((x1 * y2 - y1 * x2 + y1 * x3 - x1 * y3 + x2 * y3 - x3 * y2) / 2.0);

	return area;
}

bool check_triangle(double x, double y, Shape& shape)
{
	double x1, y1, x2, y2, x3, y3;
	double area_1, area_2, area_3, area_all;

	x1 = shape.val[0];
	y1 = shape.val[1];
	x2 = shape.val[2];
	y2 = shape.val[3];
	x3 = shape.val[4];
	y3 = shape.val[5];
	
	area_all = calculate_area(x1, y1, x2, y2, x3, y3);
	area_1	 = calculate_area(x1, y1, x2, y2, x, y);
	area_2 	 = calculate_area(x2, y2, x3, y3, x, y);
	area_3 	 = calculate_area(x3, y3, x1, y1, x, y);

	if (fabs(area_1 + area_2 + area_3 - area_all) <= 0.000001) {
		return true;
	}	

	return false;
}

int main()
{
	vector<Shape> vec_shape;

	vec_shape.reserve(16);

	// Input Processing
	char	line[512];
	while (gets(&line[0]) != NULL && line[0] != '*') {
		Shape s;

		sscanf(line, "%c %lf %lf %lf %lf %lf %lf\n", &s.shape_id, &s.val[0], &s.val[1], &s.val[2], &s.val[3], &s.val[4], &s.val[5]);

		vec_shape.push_back(s);
	}

	// Checking Each Point 
	double 	x, y;
	int		point_num = 0;
	while (scanf("%lf %lf\n", &x, &y) != EOF) {

		if (x == 9999.9 && y == 9999.9) {
			break;
		}
		
		int count = 0;
		for (int i = 0; i < vec_shape.size(); i++) {
			bool check;
			
			switch (vec_shape[i].shape_id) {
			case 'r':
				check = check_rectangle(x, y, vec_shape[i]);	
				break;
			case 'c':
				check = check_circle(x, y, vec_shape[i]);
				break;
			case 't':
				check = check_triangle(x, y, vec_shape[i]);
				break;
			default:
				break;
			}

			if (check) {
				count++;
				printf("Point %d is contained in figure %d\n", point_num + 1, i + 1);
			}
		}
		
		if (count == 0) {
			printf("Point %d is not contained in any figure\n", point_num + 1);
		}

		++point_num;
	}

	return 0;		
}

/* @END_OF_SOURCE_CODE */
