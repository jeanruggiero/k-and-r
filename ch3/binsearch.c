#include <stdlib.h>
#include <stdio.h>
#include "lighthouse.h"

/* Binsearch takes a sorted list of integers and returns the index of the first
 * occurrence of the item in the list. */
int binsearch(int length, int item) {
    printf("called binsearch.");
    int low = 0; 
    int high = length - 1; 
    int mid = 0;
/*
    while (item != list[mid]) {
        mid = (high - low)/2 + low;

        if (item < list[mid]) {
           low = mid;
        } else {
            high = mid;
        }
    }
*/
    return mid;
}

/************************* SETUP & TEARDOWN ************************/

//int *list1, *list2, *list3;

void setup() {
    int i;

    printf("Running setup ");
    //list1 = (int *) malloc(sizeof(int) * 8);
    printf("Allocated list1\n");
    //for (i = 0; i < 8; list1[i++] = 5)
    //    ;

    printf("Initializeded list1");

    /*
    list2 = (int *) malloc(sizeof(int) * 11);
    list2[0] = 3; list2[1] = 5; list2[2] = 6; list2[3] = 8; list2[4] = 11;
    list2[5] = 34; list2[6] = 55; list2[7] = 234; list2[8] = 345;
    list2[9] = 678; list2[10] = 999;

    list3 = (int *) malloc(sizeof(int) * 7);
    list3[0] = 6; list3[1] = 7; list3[2] = 8; list3[3] = 8; list3[4] = 8;
    list3[5] = 9; list3[6] = 10;
*/
}

void test_binsearch_with_homogeneous_list() {
    assert(binsearch(8, 5) == 0);
}
/*
void test_binsearch_nonexistent() {
    assert(binsearch(list2, 11, 22) == -1);
}

void test_binsearch_with_repetitions() {
    assert(binsearch(list3, 7, 8) == 2);
    assert(binsearch(list3, 7, 7) == 1);
    assert(binsearch(list3, 7, 9) == 5);
    assert(binsearch(list3, 7, 10) == 6);    
}

void test_binsearch_with_34() {
    assert(binsearch(list2, 11, 34) == 5);
    assert(binsearch(list2, 11, 678) == 9);
}*/


int main() {

    printf("Getting started");
//    before(setup);

 //   run(test_binsearch_with_homogeneous_list);
}

/*
int main() {
    run(test_binsearch_with_homogeneous_list);
    //run(test_binsearch_nonexistent);
    //run(test_binsearch_with_repetitions);
    //run(test_binsearch_with_34);

    print_testing_summary();
}*/
