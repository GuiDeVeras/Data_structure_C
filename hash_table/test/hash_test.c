#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hash.h"

void test_division_key () {
	
	assert(division_key (10, 5) == 0);
	
	assert(division_key (5, 10) == 5);
	
}

void test_multiplication_key () {
	
	assert(multiplication_key (10, 20) == 3);
	
	assert(multiplication_key (5, 10) == 0);
	
}

void test_fold_key () {
	
	assert(fold_key (71, 10) == 5);
	
	assert(fold_key (10, 7) == 2);
	
}

void test_string_value () {
	
	assert (string_value ("abcde") == 293003452);
	
	assert (string_value ("abc") == 304891);
	
}

void test_insert_hash_collision () {
	
	hash* hsh = create_hash(1024);
	
	assert(insert_hash_collision(hsh, 9) == 1);
	assert(insert_hash_collision(hsh, 999) == 1);
	
	free_hash (hsh);
	
	hash* ha = create_hash(1);
	
	assert(insert_hash_collision(ha, 1) == 1);
	assert(insert_hash_collision(ha, 0) == 0);
	
	free_hash (ha);
	
}

void test_search_hash_collision () {
	
	hash* hsh = create_hash(1024);
	int aux = 0;
	
	assert(insert_hash_collision(hsh, 9) == 1);
	assert(search_hash_collision(hsh, 9, &aux) == 1);
	assert(aux == 9);
	
	assert(search_hash_collision(hsh, 5, &aux) == 0);
	
	hash* ha = create_hash(1);
	
	assert(insert_hash_collision(ha, 1) == 1);
	assert(search_hash_collision(ha, 0, &aux) == -1);
	
	free_hash (ha);
	
	free_hash (hsh);
	
}

void test_linear_probing () {
	
	assert(linear_probing (20, 5, 4) == 1);
	
	assert(linear_probing (5, 2, 4) == 3);
}

void test_quadratic_probing () {
	
	assert(quadratic_probing (20, 5, 4) == 3);
	
	assert(quadratic_probing (5, 2, 4) == 1);
}

void test_double_hashing () {
	
	assert(double_hashing (20, 3, 5, 4) == 1);
	
	assert(double_hashing (5, 10, 2, 4) == 1);
}

void test_insert_hash_collisionless () {
		
	hash* hsh = create_hash(1024);
	
	assert(insert_hash_collisionless(hsh, 9) == 1);
	assert(insert_hash_collisionless(hsh, 999) == 1);
	
	free_hash (hsh);
	
	hash* ha = create_hash(1);
	
	assert(insert_hash_collisionless(ha, 1) == 1);
	assert(insert_hash_collisionless(ha, 0) == 0);
	
	free_hash (ha);
}

void test_search_hash_collisionless () {
	
	hash* hsh = create_hash(1024);
	int aux;
	
	assert(insert_hash_collisionless(hsh, 9) == 1);
	assert(search_hash_collisionless(hsh, 9, &aux) == 1);
	assert(aux == 9);
	
	assert(search_hash_collisionless(hsh, 999, &aux) == 0);
	
	free_hash (hsh);
	
}
