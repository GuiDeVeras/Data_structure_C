#include <stdlib.h>
#include "sequential_list.h"
#define MAX 100

struct list{
	int qtt;
	struct student data[MAX];
};

List* create_list(){
	List *li;
	li = (List*) malloc (sizeof(struct list));
	if (li != NULL){
		li->qtt = 0;
	}
	return li;
}

void free_list(List* li){
	free(li);
}
