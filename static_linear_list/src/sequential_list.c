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

int list_size(List* li){
	if (li == NULL){
		return -1;
	} else {
		return li->qtt;
	}
}

int list_full(List* li){
	if (li = NULL){
		return -1;
	}
	return (li->qtt == MAX);
}

int list_empty(List* li){
	if (li == NULL){
		return -1;
	}
	return (li->qtt == 0);
}

int insert_list_final(List* li, Student st){
	if (li == NULL){
		return 0;
	}
	if (list_full(li)){
		return 0;
	}
	li->data[li->qtt] = st;
	li->qtt++;
	return 1;
}

int insert_list_beginning(List* li, Student st){
	if(li == NULL){
		return 0;
	}
	if (list_full(li)){
		return 0;
	}
	int i;
	for (i = li->qtt-1; i >= 0; i--){
		li->data[i+1] = li->data[i];
	}
	li->data[0] = st;
	li->qtt++;
	return 1;
}

int insert_list_ordered(List* li, Student st){
	if (li == NULL){
		return 0;
	}
	if (list_full(li)){
		return 0;
	int k, i = 0;
	while (i < li->qtt && li->data[i].registration < st.registration){
		i++;
	}
	for (k = li->qtd-1; k >= i; k--){
		li->data[k+1] = li->data[k];
	}
	li->data[0] = st;
	li->qtt++;
	return 1;
}

int remove_list_final(List* li){
	if (li == NULL){
		return 0;
	}
	if (li->qtd == 0){
		return 0;
	}
	li->qtt--;
	return 1;
}

int remove_list_beginning(List* li){
	if (li == NULL){
		return 0;
	}
	if (li->qtd == 0){
		return 0;
	}
	int k = 0;
	for (k = 0; k < li->qtd-1; k++){
		li->dados[k] = li->dados[k+1];
	}
	li -> qtt--;
	return 1;
}

int remove_list(List* li){
	if (li == NULL){
		return 0;
	}
	if (li->qtd == 0){
		return 0;
	}
	int k, i = 0;
	while (i < li->qtt && li->data[i].registration != reg){
		i++;
	}
	if (i == li-> qtd){ //element not found
		return 0;
	}
	for (k = i; k >= li->qtd-1; k++){
		li->data[k] = li->data[k+1];
	}
	li->qtd--;
	return 1;
}

int consult_pos_list(List* li, int pos, Student *st){
	if(li == NULL || pos <= 0 || pos > li->qtt){
		return 0;
	}
	*st = li->data[pos-1];
	return 1;
}

int consult_pos_mat(List* li, int mat, Student *st){
	if (li == NULL){
		return 0;
	}
	int k, i = 0;
	while (i < li->qtt && li->data[i].registration != reg){
		i++;
	}
	if (i == li-> qtd){ //element not found
		return 0;
	}	
	*St = li->data[i];
	return 1;
}
