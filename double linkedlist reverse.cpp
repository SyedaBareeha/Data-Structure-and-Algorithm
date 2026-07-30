
#include<iostream>
using namespace std;


struct Node
{
    int data;
    Node* prev;
    Node* next;

    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};


// Insert at End
void insert(Node* &head, int value)
{
    Node* newNode = new Node(value);

    // If list is empty
    if(head == NULL)
    {
        head = newNode;
        return;
    }


    Node* temp = head;

    // Move to last node
    while(temp->next != NULL)
    {
        temp = temp->next;
    }


    temp->next = newNode;
    newNode->prev = temp;
}


// Print List Forward
void print(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


// Reverse Doubly Linked List
void reverse(Node* &head)
{
    Node* current = head;
    Node* temp = NULL;


    while(current != NULL)
    {
        // Swap next and prev
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;


        // Move to next node
        current = current->prev;
    }


    // Change head
    if(temp != NULL)
        head = temp->prev;
}


int main()
{
    Node* head = NULL;


    int n, value;

    cout<<"Enter number of nodes: ";
    cin>>n;


    cout<<"Enter values:\n";

    for(int i=0; i<n; i++)
    {
        cin>>value;
        insert(head,value);
    }


    cout<<"\nOriginal List: ";
    print(head);


    reverse(head);


    cout<<"\nReversed List: ";
    print(head);


    return 0;
}