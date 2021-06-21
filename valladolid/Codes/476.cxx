/* @JUDGE_ID: andrea 476 C++ "Geometry" */
/* @BEGIN_OF_SOURCE_CODE */

/*
 * Header Files
 */
#include <iostream>
#include <vector>
#include <cstdio>

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
	return true;
}

bool check_triangle(double x, double y, Shape& shape)
{
	return true;
}

int main()
{
	vector<Shape> vec_shape;

	vec_shape.reserve(16);

	// Input Processing
	char	shape_id;
	while (scanf("%c\n", &shape_id) != EOF && shape_id != '*') {
		Shape s;
		s.shape_id = shape_id;

		switch (shape_id) {
		case 'r':
			scanf("%lf %lf %lf %lf\n", &s.val[0], &s.val[1], &s.val[2], &s.val[3]);
			break;
		case 'c':
			scanf("%lf %lf %lf\n", &s.val[0], &s.val[1], &s.val[2]);
			break;
		case 't':
			scanf("%lf %lf %lf %lf %lf %lf\n", &s.val[0], &s.val[1], &s.val[2], &s.val[3], &s.val[4], &s.val[5]);
			break;
		default:
			break;
		}	

		vec_shape.push_back(s);
	}

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
