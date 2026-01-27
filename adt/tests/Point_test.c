#include <stdio.h>
#include <stdlib.h>
#include "Point.h"
int main(){
	float d;
	Point *p, *q;
	//Point r; //Error
	p = pt_create(10, 21);
	q = pt_create(7,25);
	//q->x = 2; //Error
	d = pt_distance(p,q);
	printf("Distancia entre pontos: %.2f\n", d);
	pt_free(q);
	pt_free(p);
	
	system("pause");
	return 0;
}
