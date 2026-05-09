#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "hash.h"

int main() {
	 
	 test_division_key ();
	 printf("test_division_key worked!\n");

	 test_multiplication_key ();
	 printf("test_multiplication_key worked!\n");

	 test_fold_key ();
	 printf("test_fold_key worked!\n");

	 test_string_value ();
	 printf("test_string_value worked!\n");

	 test_insert_hash_collision ();
	 printf("test_insert_hash_collision worked!\n");

	 test_search_hash_collision ();
	 printf("test_search_hash_collision worked!\n");

	 test_linear_probing ();
	 printf("test_linear_probing worked!\n");

	 test_quadratic_probing ();
	 printf("test_quadratic_probing worked!\n");

	 test_double_hashing ();
	 printf("test_double_hashing worked!\n");

	 test_insert_hash_collisionless ();
	 printf("test_insert_hash_collisionless worked!\n");

	 test_search_hash_collisionless ();
	 printf("test_insert_hash_collisionless worked!\n");
	 
	 return 0;
}
