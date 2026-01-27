#include <iostream>
using namespace std;

struct  Node {
    int data;
    Node* next;
    Node* prev;
};
Node * list=NULL;

void insert(int data) {
   Node * node = new Node();
   node->prev = NULL;
   node->next = NULL;
   node->data= data;

if(list==NULL){
    list=node;
    // node->prev = list;
    return;
}
 Node* curr = list;
    while (curr->next != NULL) {
        curr = curr->next;
    }

 node -> prev=curr;
 curr ->next = node;

}
void display() {
    Node* temp = list;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    display();   // Output: 10 20 30
    return 0;
}
