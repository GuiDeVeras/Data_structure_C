#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "hash.h"

struct Hash {
	int qtt, table_size, key, **itens;
};

hash* create_hash (int table_size) {
	hash* hsh = (hash*) malloc(sizeof(hash));
	if (hsh != NULL) {
		int i;
		hsh->table_size = table_size;
		hsh->itens = (int**) malloc (table_size * sizeof(int*));
		if (hsh->itens == NULL) {
			free (hsh);
			return NULL;
		}
		hsh->qtt = 0;
		for (i = 0; i < table_size; i++) {
			hsh->itens[i] = NULL;
		}
	}
	return hsh;
}

void free_hash (hash* hsh) {
	if (hsh != NULL) {
		int i;
		for (i = 0; i < hsh->table_size; i++) {
			if (hsh->itens[i] != NULL) free (hsh->itens[i]);
		}
		free(hsh->itens);
		free(hsh);
	}
}

int division_key (int key, int table_size) {
	return (key & 0x7FFFFFFF) % table_size;  //Bitwise operation to remove the sign bit
}

int multiplication_key (int key, int table_size) {
	float A = 0.6180339887;
	float value = key * A;
	value = value - (int) value;
	return (int) (table_size * value);
}

int fold_key (int key, int table_size) {
	int num_bits = (int)ceil(log2(table_size));
	int part1 = key >> num_bits;
	int part2 = key % (table_size);
	return (part1 ^ part2) % table_size;
}

int string_value (char *str) {
	int i, value = 7;
	int size = strlen(str);
	for (i = 0; i < size; i++) {
		value = 31 * value + (int) str[i];
	}
	return value;
}

int insert_hash_collision (hash* hsh, int value) {
	if (hsh == NULL || hsh->qtt == hsh->table_size) return 0;            
	int key = value;
	int pos = division_key (key, hsh->table_size);
	if (hsh->itens[pos] != NULL) return -1;
	hsh->itens[pos] = (int*) malloc(sizeof(int));
	if (hsh->itens[pos] == NULL) return 0;
	*(hsh->itens[pos]) = value;
	hsh->qtt++;
	return 1;	
}

int search_hash_collision (hash* hsh, int value, int *aux) {
	if (hsh == NULL) return 0;
	int pos = division_key (value, hsh->table_size);
	if (hsh->itens[pos] == NULL) return 0;
	if (*hsh->itens[pos] != value) return -1;
	*aux = *(hsh->itens[pos]);
	return 1;
}

int linear_probing (int pos, int i, int table_size) {
	return ((pos + i) & 0x7FFFFFFF) % table_size;
}

int quadratic_probing (int pos, int i, int table_size) {
	pos = pos + 2*i + 5*i*i;
	return (pos & 0x7FFFFFFF) % table_size;
}

int double_hashing (int h1, int key, int i, int table_size) {
	int h2 = division_key (key, table_size - 1) + 1;
	return ((h1 + i * h2) & 0x7FFFFFFF) % table_size;
}

int insert_hash_collisionless (hash* hsh, int value) {
	if (hsh == NULL || hsh->qtt == hsh->table_size) return 0;
	int key = value;
	int i, pos, new_pos;
	pos = division_key (key, hsh->table_size);
	for (i = 0; i < hsh->table_size; i++) {
		new_pos = linear_probing (pos, i, hsh->table_size);
		if (hsh->itens[new_pos] == NULL) {
			hsh->itens[new_pos] = (int*) malloc(sizeof(int));
			if (hsh->itens[new_pos] == NULL) return 0;			
			*(hsh->itens[new_pos]) = value;
			hsh->qtt++;
			return 1;
		}
	}
	return 0;
}

int search_hash_collisionless (hash* hsh, int value, int* aux) {
	if (hsh == NULL) return 0;
	int i, pos, new_pos;
	pos = division_key (value, hsh->table_size);
	for (i = 0; i < hsh->table_size; i++) {
		new_pos = linear_probing (pos, i, hsh->table_size);
		if (hsh->itens[new_pos] == NULL) return 0;
		if (*hsh->itens[new_pos] == value) {
			*aux = *(hsh->itens[new_pos]);
			return 1;
		}
	}
	return 0;
}
