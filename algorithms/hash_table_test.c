#include <stdlib.h>
#include "lighthouse.h"

/* Defines a node data type. */
typedef struct node {
    int data;
    struct node *next;
} node_t;

/* Defines a linked list type. */
typedef struct linked_list {
    int size;
    node_t *head;
    node_t *tail;
} list_t;

/* Defines a dict type, which is implemented as a hash table. This has table
 * only stores integer data. Each element in the table is a pointer to a linked
 * list, so that it handles collisions. */
typedef struct dict {
    int size;
    int capacity;
    list_t *data;
} dict_t;

/* Creates a new node. */
node_t *create_node(int data, node_t *next) {
    return NULL;
}

/* Creates a new linked list. */
list_t *create_list() {
    return NULL;
}

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



