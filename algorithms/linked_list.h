/* This header file contains a linked list implementation and all of the
 * functions required to create a list and add, remove, and access its elements.
 * */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <string.h>

/* Defines a node data type. */
typedef struct node {
    int value;
    char *key;
    struct node *next;
} node_t;


/* Defines a linked list type. */
typedef struct linked_list {
    int size;
    node_t *head;
} list_t;


/* Creates a new node. */
node_t *create_node(char *key, int value, node_t *next) {
    node_t *node = malloc(sizeof(node_t));
    node->value = value;

    /* Allocate enough space to store the key string. */
    node->key = (char *) calloc(sizeof(char), strlen(key));
    strcpy(node->key, key);
    node->next = next;

    return node;
}

/* Creates a new linked list. */
list_t *create_list() {
    list_t *list = malloc(sizeof(list_t));
    list->size = 0;
    list->head = NULL;

    return list;
}


/* This function finds the node corresponding to the specified key and returns a
 * pointer to that node. If the node does not exist or the list is NULL, it
 * returns NULL. */
node_t *get_node(list_t *list, char *key) {
    if (list == NULL) {
        return NULL;
    }

    node_t *node = list->head;
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return node;
        }
        node = node->next;
    }

    /* If key does not exist, return NULL. */
    return NULL;
}


/* Adds an element to the head of a linked list. Returns 1 if the operation was
 * successful or 0 if failed. If key already exists in list, its value is
 * overwritten with the new value. */
int list_add(list_t *list, char *key, int value) {
    if (list == NULL) {
        return 0;
    }

    /* First, check if key exists in list. If exists, replace its value. */
    node_t *node = get_node(list, key);
    if (node != NULL) {
        node->value = value;
        return 1;
    }

    /* If key does not exist, add new item to list. */
    list->head = create_node(key, value, list->head);
    list->size++;
    return 1;
}

/* Removes the node associated with the specified key from the linked list and
 * returns its value. Returns -1 if operation cannot be performed. */
int list_pop(list_t *list, char *key) {
    if ((list == NULL) || (list->size == 0)) {
        return -1;
    }

    node_t *node = list->head;
    int return_value = node->value;

    /* If the node to be popped is the head of the list. */
    if (strcmp(node->key, key) == 0) {
        list->head = list->head->next;
        free(node);
        list->size--;
        return return_value;
    }

    /* If the head node is not a match, check the rest of the list. */
    while (node->next != NULL) {
        /* Check if the next node matches the key.*/
        if (strcmp(node->next->key, key) == 0) {
            /* Temporary pointer to popped node. */
            node_t *popped = node->next;

            return_value = popped->value;
            node->next = node->next->next;
            free(popped);
            list->size--;
            return return_value;
        }
        node = node->next;
    }

    /* If node not found in list, return -1. */
    return -1;
}

/* Uses linear search to find and return the value associated with the specified
 * key. Returns -1 if the item is not found. */
int list_search(list_t *list, char *key) {
    /* get_node handles null list case. */
    node_t *node = get_node(list, key);
    return (node == NULL) ? -1 : node->value;
}

/* Frees the memory allocated to the linked list and each of its nodes. */
void free_list(list_t *list) {
    if (list == NULL) {
        return;
    }

    if (list->head != NULL) {
        node_t *node = list->head;
        node_t *previous = node;
        while (node->next != NULL) {
            previous = node;
            node = node->next;
            free(previous);
        }
        free(node);
    }
    free(list);
}
        

#endif
