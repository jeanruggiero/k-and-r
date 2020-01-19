#include <stdlib.h>
#include "lighthouse.h"

/* This function takes an array and recursively computes the sum of its
 * elements. It returns the sum of the elements. */
int rmax(int *list, int size) {
    if (size == 1) {
        return list[0];
    }

    int max = rmax(list + 1, --size);
    return (list[0] > max)  ? list[0] : max;
}

/************************************ TESTS ******************************/
int *list, *list1, *list2, *list3, *small_list;

void setup() {

    int i;

    list = (int *) malloc(sizeof(int) * 4);
    list[0] = -2; list[1] = -4; list[2] = -7; list[3] = -12;

    list1 = (int *) malloc(sizeof(int) * 8);
    for (i = 0; i < 8; list1[i++] = 5)
        ;

    list2 = (int *) malloc(sizeof(int) * 11);
    list2[0] = 3; list2[1] = 5; list2[2] = 6; list2[3] = 8; list2[4] = 11;
    list2[5] = 34; list2[6] = 55; list2[7] = 234; list2[8] = 345;
    list2[9] = 678; list2[10] = 999;

    list3 = (int *) malloc(sizeof(int) * 7);
    list3[0] = 6; list3[1] = 7; list3[2] = 8; list3[3] = 8; list3[4] = 8;
    list3[5] = 9; list3[6] = -10;

    small_list = (int *) malloc(sizeof(int));
    small_list[0] = 7;

}

void teardown() {
    free(list);
    free(list1);
    free(list2);
    free(list3);
}

void test_rmax_with_single_element_list() {
    assert(rmax(small_list, 1) == 7);
}

void test_rmax_with_larger_arrays() {
    assert(rmax(list, 4) == -2);
    assert(rmax(list1, 8) == 5);
    assert(rmax(list2, 11) == 999);
    assert(rmax(list3, 7) == 9);
}


int main() {
    before(setup);
    after(teardown);

    run(test_rmax_with_single_element_list);
    run(test_rmax_with_larger_arrays);

    print_testing_summary();

}
