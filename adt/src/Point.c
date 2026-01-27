//File Point.c
#include <stdlib.h>
#include <math.h>
#include "Point.h" //include the prototypes

//Definition of the data types
struct point{
	float x;
	float y;
};

//Assign and return a point with coordinates "x" and "y"
Point* pt_create(float x, float y){
	Point* p = (Point*) malloc(sizeof(Point));
	if (p != NULL){
		p->x = x;
		p->y = y;
	}
	return p;
}
//Free the memory assigned to a point
void pt_free(Point* p){
	free(p);
}
//Recover, by referece, the value of a point
void pt_acess(Point* p, float* x, float* y){
	*x = p->x;
	*y = p->y;
}
//Assign the values of "x" and "y" to a point
void pt_assign(Point*p, float x, float y){
	p->x = x;
	p->y = y;
}
//Calculate the distance between two points
float pt_distance(Point* p1, Point* p2){
	float dx = p1->x - p2->x;
	float dy = p1->y - p2->y;
	return sqrt(dx * dx + dy * dy);
}
