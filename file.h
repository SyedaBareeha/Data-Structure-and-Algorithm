#ifndef STACK_H
#define STACK_H

struct stackNode {
    int data;
    stackNode* next;
};

extern stackNode* top;

void push(int data);
void pop();
int peek();
bool isEmpty();

#endif