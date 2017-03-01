//
// Created by wangyang on 17/3/1.
//

#ifndef OLED_CLION_TESTS_LINKEDARRAY_TESTS_H
#define OLED_CLION_TESTS_LINKEDARRAY_TESTS_H

#include <LinkedArray.h>

typedef struct {
    int a;
    int b;
} TestNode;

class LinkedArray_tests {
public:
    void test_add() {
        LinkedArray array;
        for (int i = 0; i < 6; ++i) {
            array.add(createNode(i, i + 1));
        }
        for (int i = 0; i < 6; ++i) {
            TestNode *nodeOut = (TestNode *)array.at(i);
            printNode(nodeOut);
        }
    }

    void test_size() {
        LinkedArray array;
        for (int i = 0; i < 6; ++i) {
            array.add(createNode(i, i + 1));
        }
        printf("Size: %d\n", array.size());
    }

    void test_remove() {
        LinkedArray array;
        for (int i = 0; i < 6; ++i) {
            array.add(createNode(i, i + 1));
        }
        array.removeAt(0);
        for (int i = 0; i < array.size(); ++i) {
            TestNode *nodeOut = (TestNode *)array.at(i);
            printNode(nodeOut);
        }
    }

    void test_clear() {
        LinkedArray array;
        for (int i = 0; i < 6; ++i) {
            array.add(createNode(i, i + 1));
        }
        array.clear();
        for (int i = 0; i < array.size(); ++i) {
            TestNode *nodeOut = (TestNode *)array.at(i);
            printNode(nodeOut);
        }
        printf("Size: %d\n", array.size());
    }

private:
    TestNode *createNode(int a, int b) {
        TestNode *node = (TestNode *)malloc(sizeof(TestNode));
        node->a = a;
        node->b = b;
        return node;
    }

    void printNode(TestNode *node) {
        printf("Node: %d, %d\n", node->a, node->b);
    }
};


#endif //OLED_CLION_TESTS_LINKEDARRAY_TESTS_H
