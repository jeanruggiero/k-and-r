#include <stdlib.h>
#include <stdio.h>
#include "lighthouse.h"

/* This function takes a sorted list, the size of the list, and an item to find
 * within the list. It returns the index of the first occurrence of item in the
 * list. If item is not in the list, it returns -1. */
int binsearch(int *list, int size, int item) {
    if (list == NULL) {
        return -2;
    }

    int high = size - 1;
    int low = 0;
    int mid = 0;

    while (high > low) {
        mid = (high - low)/2 + low;

        if (item > list[mid]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return (list[low] == item) ? low : -1;
}

/************************************ TESTS ******************************/
int *list, *list1, *list2, *list3;

void set_up() {
    
    int i;
    
    list = (int *) malloc(sizeof(int) * 4);
    list[0] = 2; list[1] = 4; list[2] = 7; list[3] = 12;

    list1 = (int *) malloc(sizeof(int) * 8);
    for (i = 0; i < 8; list1[i++] = 5)
        ;

    list2 = (int *) malloc(sizeof(int) * 11);
    list2[0] = 3; list2[1] = 5; list2[2] = 6; list2[3] = 8; list2[4] = 11;
    list2[5] = 34; list2[6] = 55; list2[7] = 234; list2[8] = 345;
    list2[9] = 678; list2[10] = 999;
    
    list3 = (int *) malloc(sizeof(int) * 7);
    list3[0] = 6; list3[1] = 7; list3[2] = 8; list3[3] = 8; list3[4] = 8;
    list3[5] = 9; list3[6] = 10;

}

void teardown() {
    free(list);
    free(list1);
    free(list2);
    free(list3);
}

void test_binsearch_with_small_list() {
    assert(binsearch(list, 4, 7) == 2);
}

void test_binsearch_with_nonexistent_item() {
    assert(binsearch(list, 4, 15) == -1);
    assert(binsearch(list, 4, 0) == -1);
    assert(binsearch(list, 4, 6) == -1);
}

void test_binsearch_with_long_list() {
    assert(binsearch(list2, 11, 234) == 7);
    assert(binsearch(list2, 11, 999) == 10);
    assert(binsearch(list2, 11, 77) == -1);
    assert(binsearch(list2, 11, 3) == 0);
    assert(binsearch(list2, 11, 2) == -1);
}

void test_binsearch_with_homogeous_list() {
    assert(binsearch(list1, 8, 5) == 0);
    assert(binsearch(list1, 8, 4) == -1);
    assert(binsearch(list1, 8, 6) == -1);
}

void test_binsearch_with_repeats() {
    assert(binsearch(list3, 7, 8) == 2);
    assert(binsearch(list3, 7, 7) == 1);
    assert(binsearch(list3, 7, 9) == 5);
}

void test_binsearch_with_null_list() {
    int *null_list = NULL;
    assert(binsearch(null_list, 3, 1) == -2);
}

/*********************************** RUN TESTS ****************************/
int main(){

    /* Indicate your setup (before) and teardown (after) functions. */
    before(set_up);
    after(teardown);

    /* For each test you'd like to run, call run() with the name of the test 
     * function to run. */
    run(test_binsearch_with_small_list);
    run(test_binsearch_with_nonexistent_item);
    run(test_binsearch_with_long_list);
    run(test_binsearch_with_homogeous_list);
    run(test_binsearch_with_repeats);
    run(test_binsearch_with_null_list);

    print_testing_summary();

    return 0;
}
