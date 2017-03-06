//
// Created by wangyang on 17/3/1.
//

#ifndef OLED_CLION_LINKEDARRAY_H
#define OLED_CLION_LINKEDARRAY_H

#include <stdint.h>
#include <stdlib.h>

#define NULL 0

struct _LinkedNode{
    void *data;
    struct _LinkedNode *next;
};
typedef struct _LinkedNode LinkedNode;

class LinkedArray {
public:
    LinkedArray() {
        tail = NULL;
        head = NULL;
    }
    void add(void *data) {
        createNode(data);
    }

    void removeAt(int16_t index) {
        int16_t _index = 0;
        if (index == 0) {
            LinkedNode *originHead = head;
            head = originHead->next;
            deleteNode(originHead);
            return;
        }
        LinkedNode *pNode = head;
        while(pNode != NULL) {
            if (_index == index - 1) {
                LinkedNode *originNode = pNode->next;
                pNode->next = pNode->next->next;
                deleteNode(originNode);
                return;
            }
            pNode = pNode->next;
            _index ++;
        }
    }

    int16_t size() {
        int16_t size = 0;
        LinkedNode *pNode = head;
        while(pNode != NULL) {
            size++;
            pNode = pNode->next;
        }
        return size;
    }

    void * at(int16_t index) {
        int16_t _index = index;
        LinkedNode *pNode = head;
        while (_index--) {
            pNode = pNode->next;
        }
        return pNode->data;
    }

    void clear() {
        freeAll();
        head = NULL;
        tail = NULL;
    }

private:
    LinkedNode *tail;
    LinkedNode *head;
    LinkedNode *createNode(void *data) {
        LinkedNode *node = (LinkedNode *)malloc(sizeof(LinkedNode));
        if (head == NULL) {
            head = node;
            head->data = data;
            head->next = NULL;
            tail = head;
        } else {
            node->data = data;
            tail->next = node;
            tail = node;
        }
        return node;
    }

    void deleteNode(LinkedNode *node) {
        free(node->data);
        free(node);
    }

    void freeAll() {
        LinkedNode *pNode = head;
        while (pNode) {
            LinkedNode *nextNode = pNode->next;
            deleteNode(pNode);
            pNode = nextNode;
        }
    }
};


#endif //OLED_CLION_LINKEDARRAY_H
