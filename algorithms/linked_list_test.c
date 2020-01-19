/* This file includes all of the tests for the linked list implementation. */

#include <string.h>
#include "linked_list.h"
#include "lighthouse.h"

node_t *test_node;
list_t *test_list, *null_list = NULL, *list2;

void setup() {
    test_node = create_node("Billy", 3, NULL);
    test_list = create_list();
    list2 = create_list();

    assert(list_add(list2, "johnny", 42) == 1);
    assert(list_add(list2, "bobby", 77) == 1);
    assert(list_add(list2, "bo", 7) == 1);
    assert(list_add(list2, "tanya", 22) == 1);
    assert(list_add(list2, "mary", 80) == 1);
}

void teardown() {
    free(test_node);
    free(test_list);
}


void test_create_node() {
    assert(test_node->value == 3);
    assert(strcmp(test_node->key, "Billy") == 0);
    assert(test_node->next == NULL);
}

void test_create_list() {
    assert(test_list->head == NULL);
    assert(test_list->size == 0);
}

void test_list_add_with_null_list() {
    assert(list_add(null_list, "Frank", 88) == 0);
}

void test_list_add() {
    assert(list_add(test_list, "Joe", 6) == 1);
    assert(test_list->head->value == 6);
    assert(strcmp(test_list->head->key, "Joe") == 0);
    assert(test_list->head->next == NULL);
    assert(test_list->size == 1);

    assert(list_add(test_list, "Mom", 65) == 1);
    assert(test_list->head->value == 65);
    assert(strcmp(test_list->head->key, "Mom") == 0);
    assert(test_list->head->next->value == 6);
    assert(strcmp(test_list->head->next->key, "Joe") == 0);
    assert(test_list->head->next->next == NULL);
    assert(test_list->size == 2);
}

void test_list_add_with_key_that_already_exists() {
    assert(list_add(test_list, "Joe", 6) == 1);
    assert(test_list->head->value == 6);
    assert(strcmp(test_list->head->key, "Joe") == 0);
    assert(test_list->head->next == NULL);

    assert(list_add(test_list, "Mom", 65) == 1);
    assert(test_list->head->value == 65);
    assert(strcmp(test_list->head->key, "Mom") == 0);
    assert(test_list->head->next->value == 6);
    assert(strcmp(test_list->head->next->key, "Joe") == 0);
    assert(test_list->head->next->next == NULL);
    assert(test_list->size == 2);

    assert(list_add(test_list, "Joe", 33) == 1);
    assert(test_list->head->value == 65);
    assert(strcmp(test_list->head->key, "Mom") == 0);
    assert(test_list->head->next->value == 33);
    assert(strcmp(test_list->head->next->key, "Joe") == 0);
    assert(test_list->head->next->next == NULL);
    assert(test_list->size == 2);
    
    assert(list_add(test_list, "Mom", 57) == 1);
    assert(test_list->head->value == 57);
    assert(strcmp(test_list->head->key, "Mom") == 0);
    assert(test_list->head->next->value == 33);
    assert(strcmp(test_list->head->next->key, "Joe") == 0);
    assert(test_list->head->next->next == NULL);
    assert(test_list->size == 2);
}

void test_list_search_with_null_list() {
    assert(list_search(null_list, "terry") == -1);
}

void test_list_search_nonexistent() {
    assert(list_search(list2, "pete") == -1);
    assert(list_search(list2, "Bobby") == -1);
}

void test_list_search() {
    assert(list_search(list2, "johnny") == 42);
    assert(list_search(list2, "bobby") == 77);
    assert(list_search(list2, "bo") == 7);
    assert(list_search(list2, "tanya") == 22);
    assert(list_search(list2, "mary") == 80);
}

void test_list_pop_with_null_list() {
    assert(list_pop(null_list, "frank") == -1);
}

void test_list_pop_with_empty_list() {
    assert(list_pop(test_list, "sue") == -1);
}

void test_list_pop_nonexistent() {
    assert(list_pop(list2, "Johnny") == -1);
    assert(list_pop(list2, "andrew") == -1);
}

void test_list_pop_from_list_head() {
    assert(list_pop(list2, "mary") == 80);
    assert(list2->size == 4);
    assert(list2->head->value == 22);
    assert(strcmp(list2->head->key, "tanya") == 0);
    assert(list2->head->next->value == 7);
    assert(strcmp(list2->head->next->key, "bo") == 0);
}

void test_list_pop_from_list_tail() {
    assert(list_pop(list2, "johnny") == 42);
    assert(list2->size == 4);
    assert(list2->head->next->next->next->value == 77);
    assert(strcmp(list2->head->next->next->next->key, "bobby") == 0);
    assert(list2->head->next->next->next->next == NULL);
}

void test_list_pop_from_list_middle() {
    assert(list_pop(list2, "tanya") == 22);
    assert(list2->size == 4);
    assert(list2->head->value == 80);
    assert(strcmp(list2->head->key, "mary") == 0);
    assert(list2->head->next->value == 7);
    assert(strcmp(list2->head->next->key, "bo") == 0);
}

void test_list_pop_that_empties_list() {
    assert(list_pop(list2, "bobby") == 77);
    assert(list_pop(list2, "mary") == 80);
    assert(list_pop(list2, "tanya") == 22);
    assert(list_pop(list2, "johnny") == 42);
    assert(list_pop(list2, "bo") == 7);

    assert(list2->size == 0);
    assert(list2->head == NULL);
}

int main() {
    before(setup);
    after(teardown);
    
    run(test_create_node);
    run(test_create_list);

    run(test_list_add_with_null_list);
    run(test_list_add);
    run(test_list_add_with_key_that_already_exists);
    
    run(test_list_search_with_null_list);
    run(test_list_search_nonexistent);
    run(test_list_search);
 
    run(test_list_pop_with_null_list);
    run(test_list_pop_with_empty_list);
    run(test_list_pop_nonexistent);
    run(test_list_pop_from_list_head);
    run(test_list_pop_from_list_tail);
    run(test_list_pop_from_list_middle);
    run(test_list_pop_that_empties_list);
    print_testing_summary();
}
