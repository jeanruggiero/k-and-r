#include <stdlib.h>
#include "lighthouse.h"


/* This function sorts a list of integers in ascending order in place using 
 *  quicksort. It returns 1 if the sort operation was successful or 
 * -1 if the list is NULL. */
int quicksort(int *list, int size) {
    
    /* Base case */
    if (list == NULL) {   
        return -1;
    } else if (size < 2) {
        return size;
    }  

    /* Recursive case */
    int pivot = rand() % size;
    int pivot_value = list[pivot];
    int size_left = 0, size_right = 0;

    int *left = (int *) calloc(sizeof(int), size - 1);
    int *right = (int *) calloc(sizeof(int), size - 1);

    int i = 0, j = 0;

    /* Partition the list around the pivot. */
    for (i = 0; i < size; i++) {
        if (i == pivot) {
            continue;
        }

        if (list[i] < list[pivot]) {
            left[size_left] = list[i];
            size_left++;
        } else {
            right[size_right] = list[i];
            size_right++;
        }
    }

    /* Sort the left and right partitions recursively. */
    size_left = quicksort(left, size_left);
    size_right = quicksort(right, size_right);

    /* Copy the sorted left partition, then the pivot, then the sorted right
     * partition into the original list. */
    for (i = 0; i < size_left; i++) {
        list[i] = left[i];
    }
    list[i++] = pivot_value;

    for (j = 0; j < size_right; j++, i++) {
        list[i] = right[j];
    }
    
    free(left);
    free(right);

    return size;
}


/****************************** TESTS ****************************/

int *list1, *list2, *list3, *short_list;

void setup() {
    list1 = (int *) malloc(sizeof(int) * 4);
    list1[0] = 88; list1[1] = 3; list1[2] = 67; list1[3] = 1;

    list2 = (int *) malloc(sizeof(int) * 7);
    list2[0] = 9; list2[1] = 0; list2[2] = -66; list2[3] = 99;
    list2[4] = 8; list2[5] = -2; list2[6] = 5;

    list3 = (int *) malloc(sizeof(int));
    list3[0] = 88;

    short_list = (int *) malloc(sizeof(int) * 2);
    short_list[0] = 55; short_list[1] = 8;
}

void teardown() {
    free(list1);
    free(list2);
    free(list3);
}

void test_quicksort_with_null_list() {
    int * null_list = NULL;

    assert(quicksort(null_list, 0) == -1);
}

void test_quicksort_on_single_element_list() {
    assert(quicksort(list3, 1) == 1);
    assert(list3[0] == 88);
}

void test_quicksort_on_two_element_list() {
    assert(quicksort(short_list, 2) == 2);
    assert(short_list[0] == 8);
    assert(short_list[1] == 55);
}

void test_quicksort_on_short_list() {
    assert(quicksort(list1, 4) == 4);
    assert(list1[0] == 1);
    assert(list1[1] == 3);
    assert(list1[2] == 67);
    assert(list1[3] == 88);
}

void test_quicksort_on_long_list() {
    assert(quicksort(list2, 7) == 7);
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

    run(test_quicksort_with_null_list);
    run(test_quicksort_on_two_element_list);
    run(test_quicksort_on_single_element_list);
    run(test_quicksort_on_short_list);
    run(test_quicksort_on_long_list);

    print_testing_summary();
}

