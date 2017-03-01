//
// Created by wangyang on 17/3/1.
//

#include <stdlib.h>
#include <stdio.h>

#include "LinkedArray_tests.h"
int main(int argc, const char **argv) {
    printf("Test Begin\n");

    LinkedArray_tests test;
    test.test_add();
    test.test_size();
    test.test_remove();
    test.test_clear();
    return 0;
}