#include <iostream>
using namespace std;

struct LLNode{
        int data;
        LLNode* next;
};
    LLNode* list=NULL;

void insert(int data) {
    LLNode* temp = new LLNode;
    temp->data = data;
    temp->next = NULL;
    if(list == NULL) {
        list = temp;
    }else {
        LLNode* curr = list;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

void display() {
    LLNode* temp = list;
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void Search(int val) {
    int found=-1;
    LLNode* temp = list;
    while(temp != NULL) {
        if (temp->data == val) {
            found=1;
            cout<<"Found"<<endl;
            break;
        }else{
            temp = temp->next;
        }
    }
    if (found==-1) {
        cout<<"Not Found"<<endl;
    }

}
// Function to delete a node by value
void deleteNode(int val){

    // Empty list check
    if(list == NULL){
        cout<<"List empty"<<endl;  
        return;
    }

    // First node delete
    if(list->data == val){
        LLNode* temp = list;
        list = list->next;
        delete temp;
        cout<<"Deleted"<<endl;
        return;
    }

    // Middle or last
    LLNode* curr = list;

    while(curr->next != NULL){

        if(curr->next->data == val){
            LLNode* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            cout<<"Deleted"<<endl;
            return;
        }

        curr = curr->next;
    }

    cout<<"Not Found"<<endl;
}


int main() {

    cout<<"Hi this is LinkedList app"<<endl;

    cout<<"1- Insert Data"<<endl;
    cout<<"2- Display"<<endl;
    cout<<"3- Search"<<endl;
    cout<<"4- Delete"<<endl;
    cout<<"5- Exit"<<endl;



    int choice=-1;

    while(choice!=5) {

        cout<<"Enter the choice"<<endl;
        cin>>choice;

        switch(choice) {
            case 1:
                cout<<"Enter the value you wanna insert"<<endl;
                int value;
                cin>>value;
                insert(value);
                break;
            case 2:
                cout<<"Displaying"<<endl;
                display();
                break;
            case 3:
                cout<<"Searching"<<endl;
                cout<<"Enter the value you wanna Search"<<endl;
                int val;
                cin>>val;
                Search(val);
                break;
            case 4:
                cout<<"Exiting"<<endl;
                exit(0);
            case 5:
                cout<<"Del"<<endl;
                int toDel;
                cin>>toDel;
                deleteNode(toDel);
                break;
            default:
                cout<<"Invalid choice"<<endl;
        }
    }
}