#include<iostream>
#include<stack>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

// Insert at End
void insertEnd(Node* &head,int val)
{
    Node* newNode=new Node(val);

    if(head==NULL)
    {
        head=newNode;
        return;
    }

    Node* temp=head;

    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newNode;
}

// Display
void display(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

// Insert according to question
void insertNth(Node* &head,int value,int n)
{
    Node* newNode=new Node(value);

    if(n<=1)
    {
        newNode->next=head;
        head=newNode;
        return;
    }

    Node* temp=head;
    int count=1;

    while(temp!=NULL && count<n-1)
    {
        temp=temp->next;
        count++;
    }

    // Position exists
    if(temp!=NULL)
    {
        newNode->next=temp->next;
        temp->next=newNode;
    }

    // Position does not exist
    else
    {
        if(value%2!=0)       // Odd
        {
            newNode->next=head;
            head=newNode;
        }
        else                 // Even
        {
            insertEnd(head,value);
        }
    }
}

// Reverse Display using Iteration
void reverseDisplay(Node* head)
{
    stack<int> st;

    while(head!=NULL)
    {
        st.push(head->data);
        head=head->next;
    }

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main()
{
    Node* head=NULL;

    insertEnd(head,10);
    insertEnd(head,20);
    insertEnd(head,30);
    insertEnd(head,40);
    insertEnd(head,50);

    cout<<"Original List: ";
    display(head);

    int id=767;
    int position=id%10;

    int value;

    cout<<"\nEnter value to insert: ";
    cin>>value;

    insertNth(head,value,position);

    cout<<"\nAfter Insertion: ";
    display(head);

    cout<<"\nReverse Display: ";
    reverseDisplay(head);

    return 0;
}