#include <iostream>
using  namespace std;

struct LLNode{
    int data;
    LLNode* next;
};
LLNode* list=NULL;


void insert(int data) {

    LLNode* node = new LLNode();
    node->data = data;

    if(list==NULL) {
        list = node;
        node->next = list;
        return;
    }
    LLNode* curr= list;
    while(curr->next != list) {
        curr = curr->next;
    }
    curr->next = node;
    node->next = list;

}

void search(int data) {
    if (list == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    LLNode* curr = list;

    do {
        if (curr->data == data) {
            cout << "Found" << endl;
            return;
        }
        curr = curr->next;
    } while (curr != list);

    cout << "Not Found" << endl;
}

void delNode(int data) {
    LLNode* curr = list;
    LLNode* prev = NULL;

    if (list==NULL) {
        cout<<"List is Empty"<<endl;
        return;
    }
    //for only one node
    if (curr->data== data && curr->next==list) {
        cout<<"Deleted"<<endl;
        list=NULL;
        free(curr);
        return;
    }
    //head
    if (list->data == data) {
        LLNode *temp = list;
        while (curr->next != list) {
            curr= curr->next;
        }
        curr->next = temp->next;
        list=list->next;
        free(temp);
        cout<<"Deleted"<<endl;
        return;
    }


    //middle

    prev = list;
    curr = list->next;

    while (curr != list && curr->data != data) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == list) {
        cout << "Not Found\n";
    }
    else {
        prev->next = curr->next;
        free(curr);
        cout<<"Deleted"<<endl;
    }


}
void display() {
    LLNode* temp = list;
    if (list==NULL) {
        cout<<"List is Empty"<<endl;
        return;
    }
    do {
        cout<<temp->data<<" ";
        temp = temp->next;
    }while (temp != list);
    cout<<endl;
}

int main() {
    cout<<"Hi this is  Circular LinkedList app"<<endl;

    cout<<"1- Insert Data"<<endl;
    cout<<"2- Display"<<endl;
    cout<<"3- Search"<<endl;
    cout<<"4- Delete"<<endl;
    cout<<"5- Exit"<<endl;
    int val;
    int choice = -1;
    while(choice!=5) {
        cout<<"Enter Choice"<<endl;
        cin>>choice;
        switch (choice) {
            case 1:
                cout<<"Enter Data"<<endl;
                cin>>val;
                insert(val);
                break;
            case 2:
                cout<<"Display"<<endl;
                display();
                break;
            case 3:
                cout<<"Search"<<endl;
                cin>>val;
                search(val);
                break;
            case 4:
                cout<<"To Delete enter value"<<endl;
                cin>>val;
                delNode(val);
                break;
            case 5:
                cout<<"Exit"<<endl;
                return 0;
            default:
                cout<<"Wrong Choice"<<endl;
        }
    }


}
