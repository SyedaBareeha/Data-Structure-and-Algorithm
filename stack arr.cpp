#include <iostream>
using namespace std;

#define SIZE 5

int stackArr[SIZE];
int top = -1;  // Stack empty

//  Check Overflow
bool isOverflow() {
    return (top == SIZE - 1);
}

//  Check Underflow
bool isUnderflow() {
    return (top == -1);
}

//  PUSH
void push(int data) {
    if (isOverflow()) {
        cout << "Stack Overflow! Cannot push " << data << endl;
        return;
    }
    stackArr[++top] = data;
    cout << data << " pushed into stack." << endl;
}

//  POP
void pop() {
    if (isUnderflow()) {
        cout << "Stack Underflow! Nothing to pop." << endl;
        return;
    }
    cout << stackArr[top--] << " popped from stack." << endl;
}

//  DISPLAY
void display() {
    if (isUnderflow()) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack elements (top to bottom): ";
    for (int i = top; i >= 0; i--) {
        cout << stackArr[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "WELCOME TO ARRAY STACK WORLD :)" << endl;

    int choice, data;

    while (true) {
        cout << "\n1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to push: ";
                cin >> data;
                push(data);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }
}