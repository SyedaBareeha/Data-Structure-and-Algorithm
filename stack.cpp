#include <iostream>
using namespace std;
struct stackNode {
    int data;
    stackNode* next;
};
stackNode* top= NULL;

void push(int data) {
    stackNode* newNode = new stackNode;
    newNode->data = data;
    newNode->next = top;
}

void pop() {
    stackNode* temp = top;
    if(top == NULL) {
        cout<<"Stack is empty"<<endl;
        return;
    }
    top = top->next;
    delete temp;
}
int main() {
cout<<"WELCOME TO STACK WORLD :)"<<endl;
    cout<<"1. PUSH TO STACK"<<endl;
    cout<<"2. POP TO STACK"<<endl;
    cout<<"3. EXIT"<<endl;
    int choice;

    int data;
    while(choice!=3) {
        cout<<"Enter choice "<<endl;
        cin>>choice;
        switch(choice) {
            case 1:
            cout<<"Enter element to be pushed: "<<endl;
            cin>>data;
            push(data);
            break;
            case 2:
            pop();
            break;
            case 3:
            cout<<"Exiting..."<<endl;
            return 0;
            default:
            cout<<"Invalid choice"<<endl;
        }
    }



}