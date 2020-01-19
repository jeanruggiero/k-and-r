/* This file contains an implementation of a hash table data structure. It
 * relies on the linked list implementation I created in linked_list.h. Each
 * element in the hash table's data array is a pointer. If no data is stored in
 * the array location, the pointer is NULL. If data is added at that location, a
 * linked list is created and the array location is pointed to the newly created
 * list. Collisions are handled by adding the item to the front of the linked
 * list. */

#include <stdlib.h>
#include "linked_list.h"

/* Defines a dict type, which is implemented as a hash table. This hash table
 * only stores integer data. Each element in the table is a pointer to a linked
 * list, so that it handles collisions. */
typedef struct dict {
    int size;
    int capacity;
    list_t *data;
} dict_t;


/* Creates a new hash table of the specified capacity. */
dict_t *create_hash(int capacity) {
    
    if (capacity < 1) {
        return NULL;
    }

    dict_t *dict = malloc(sizeof(dict_t));
    dict->size = 0;
    dict->capacity = capacity;
    dict->data = (list_t *) malloc(sizeof(list_t) * capacity);

    int i;
    for (i = 0; i < capacity; i++) {

    return dict;
}

/* Returns the load factor of a hash table. */
int hash_load_factor(dict_t *dict) {
    return 0;
}

/* Hash function to map keys to list indices. */
int hash(char *key) {
    return 9999;
}

/* Rehashes a hash table, doubling it in size and rehashing each element. */
void hash_rehash(dict_t **dict_ptr) {
}

/* Adds an element to the hash table. */
void hash_add(dict_t *dict, int data) {
}


/* Returns an element from the hash table based on its key. */
int hash_get(dict_t *dict, char *key) {
    return 0;
}


/* Removes and returns an element from the hash table based on its key. */
int hash_pop(dict_t *dict, char *key) {
    return 0;
}

/* Frees a hash table from memory. */
void free_hash(dict_t **dict) {
}




/*********************** TESTS ********************/

node_t *test_node;
dict_t *ages, *null_dict;

void setup() {
    test_node = create_node(3, null);
    ages = create_hash(10);
    null_dict = create_hash(0);
}

void teardown() {
    free(ages);
}

void test_create_hash() {
    assert(ages->size == 0);
    assert(ages->capacity == 10);
    assert(ages->data->size == 0);
    assert(ages->data->head == NULL);
    assert(ages->data->tail == NULL);
}

void test_create_hash_table_with_capacity_zero() {
    assert(null_dict == NULL);
}


int main() {
    before(setup);
    after(teardown);
    
    run(test_create_hash);
    run(test_create_hash_table_with_capacity_zero);

    print_testing_summary();
}



