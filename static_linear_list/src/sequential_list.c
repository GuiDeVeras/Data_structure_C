#include <stdio.h>
#include <stdlib.h>
#include "sequential_list.h"
#define MAX 100

struct list{
	int qtt;
	Student data[MAX];
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
	if (li == NULL){
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
	}
	int k, i = 0;
	while (i < li->qtt && li->data[i].registration < st.registration){
		i++;
	}
	for (k = li->qtt-1; k >= i; k--){
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
	if (li->qtt == 0){
		return 0;
	}
	li->qtt--;
	return 1;
}

int remove_list_beginning(List* li){
	if (li == NULL){
		return 0;
	}
	if (li->qtt == 0){
		return 0;
	}
	int k = 0;
	for (k = 0; k < li->qtt-1; k++){
		li->data[k] = li->data[k+1];
	}
	li -> qtt--;
	return 1;
}

int remove_list(List* li, int reg){
	if (li == NULL){
		return 0;
	}
	if (li->qtt == 0){
		return 0;
	}
	int k, i = 0;
	while (i < li->qtt && li->data[i].registration != reg){
		i++;
	}
	if (i == li-> qtt){ //element not found
		return 0;
	}
	if (i == 1){
		return 1;
	}
	for (k = i; k >= li->qtt-1; k--){
		li->data[k] = li->data[k+1];
	}
	li->qtt--;
	return 1;
}

int consult_pos_list(List* li, int pos, Student *st){
	if(li == NULL || pos <= 0 || pos > li->qtt){
		return 0;
	}
	*st = li->data[pos-1];
	return 1;
}

int consult_pos_reg(List* li, int reg, Student *st){
	if (li == NULL){
		return 0;
	}
	int k, i = 0;
	while (i < li->qtt && li->data[i].registration != reg){
		i++;
	}
	if (i == li-> qtt){ //element not found
		return 0;
	}
	*st = li->data[i];
	return 1;
}

void print_list(List *li) {
    if (li == NULL || list_empty(li)) {
        printf("The list is empty or doesn't exist.\n");
        return;
    }
    printf("\n--- STUDENTS (%d) ---\n", li->qtt);
    for (int i = 0; i < li->qtt; i++) {
        printf("Position %d:\n", i + 1);
        printf("  Registration: %d\n", li->data[i].registration);
        printf("  Name: %s\n", li->data[i].name);
        printf("  Grades: %.1f, %.1f, %.1f\n", 
                li->data[i].n1, 
                li->data[i].n2, 
                li->data[i].n3);
        printf("------------------\n");
    }
}
