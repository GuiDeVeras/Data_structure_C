//File Point.h
typedef struct point Point;

//Create a new point
Point* pt_create(float x, float y);
//Free a point
void pt_free(Point* p);
//Acess the values of "x" and "y" of a point
void pt_acess(Point* p, float* x, float* y);
//Assign the values of "x" and "y" to a point
void pt_assign(Point*p, float x, float y);
//Calculate the distance between two points
float pt_distance(Point* p1, Point* p2);
