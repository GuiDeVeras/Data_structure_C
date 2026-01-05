#include <stdlib.h>
#include "sequential_list.h"
#define MAX 100

struct list{
	int qtd;
	struct student data[MAX];
};

List* create_list(){
	List *li;
	li = (List*) malloc (sizeof(struct list));
	if (li != NULL){
		li->qtd = 0;
	}
	return li;
}

void free_list(List* li){
	free(li);
}
