#include <iostream>
#include "file.h"
using namespace std;

stackNode* top = NULL;

void push(int data) {
    stackNode* newNode = new stackNode;
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL) return;

    stackNode* temp = top;
    top = top->next;
    delete temp;
}

int peek() {
    if (top == NULL) return -1;
    return top->data;
}

bool isEmpty() {
    return top == NULL;
}