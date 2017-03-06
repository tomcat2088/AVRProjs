//
// Created by wangyang on 17/3/1.
//

#include <stdlib.h>
#include <stdio.h>

#include "LinkedArray_tests.h"
#include "Graphics_tests.h"

int main(int argc, const char **argv) {
    printf("Test Begin\n");

    LinkedArray_tests test;
    test.test_add();
    test.test_size();
    test.test_remove();
    test.test_clear();

    Graphics_tests test2;
    test2.test_draw();
    return 0;
}