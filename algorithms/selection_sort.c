#include <stdlib.h>
#include "lighthouse.h"


/* This function removes the item at index from the given array and returns 
 * the new size of the array. It does not free memory. */
int array_remove(int *list, int size, int index) {
    if ((list == NULL) || (index >= size)) {
        return -1;
    }

    int i;

    for (i = index; i < size - 1; i++) {
        list[i] = list[i + 1];
    }

    return --size;
}


/* This function sorts a list of integers in ascending order in place using 
 *  selection sort. It returns 1 if the sort operation was successful or 
 * -1 if the list is NULL. */
int sel_sort(int *list, int size) {
    if (list == NULL) {
        return -1;
    }

    int *sorted = (int *) calloc(sizeof(int), size);
    int original_size = size;
    int i, j, min_index = 0;

    /* While the original array is not empty, find the min item in it. */
    for (i = 0; size > 0; i++) {
        min_index = 0;

        for (j = 1; j < size; j++) {
            if (list[j] < list[min_index]) {
                min_index = j;
            }
        }

        /* Assign the min item to the next position in the sorted list. */
        sorted[i] = list[min_index];
        /* Remove the item from the original array. */
        size = array_remove(list, size, min_index);
    }

    /* Copy the sorted array into the memory locaiton of the original array. */
    for (i = 0; i < original_size; i++) {
        list[i] = sorted[i];
    }

    free(sorted);
    return 1;
}





/****************************** TESTS ****************************/

int *list1, *list2, *list3;

void setup() {
    list1 = (int *) malloc(sizeof(int) * 4);
    list1[0] = 88; list1[1] = 3; list1[2] = 67; list1[3] = 1;

    list2 = (int *) malloc(sizeof(int) * 7);
    list2[0] = 9; list2[1] = 0; list2[2] = -66; list2[3] = 99;
    list2[4] = 8; list2[5] = -2; list2[6] = 5;

    list3 = (int *) malloc(sizeof(int));
    list3[0] = 88;
}

void teardown() {
    free(list1);
    free(list2);
    free(list3);
}

void test_sel_sort_with_null_list() {
    int * null_list = NULL;

    assert(sel_sort(null_list, 0) == -1);
}

void test_sel_sort_on_single_element_list() {
    assert(sel_sort(list3, 1) == 1);
    assert(list3[0] == 88);
}

void test_sel_sort_on_short_list() {
    assert(sel_sort(list1, 4) == 1);
    assert(list1[0] == 1);
    assert(list1[1] == 3);
    assert(list1[2] == 67);
    assert(list1[3] == 88);
}

void test_sel_sort_on_long_list() {
    assert(sel_sort(list2, 7) == 1);
    assert(list2[0] == -66);
    assert(list2[1] == -2);
    assert(list2[2] == 0);
    assert(list2[3] == 5);
    assert(list2[4] == 8);
    assert(list2[5] == 9);
    assert(list2[6] == 99);
}

int main() {

    before(setup);
    after(teardown);

    run(test_sel_sort_with_null_list);
    run(test_sel_sort_on_single_element_list);
    run(test_sel_sort_on_short_list);
    run(test_sel_sort_on_long_list);

    print_testing_summary();
}

