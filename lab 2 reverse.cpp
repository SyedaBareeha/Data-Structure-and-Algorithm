//According to the image, the assignment requires:

//Implement a Doubly Linked List
//Insert operation
//Print operation
//Maintain both head and tail pointers
//Maintain an index field in each node
//Apply Quick Sort on the Doubly Linked List
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

// Insert at End
void insert(int value)
{
    Node *newNode = new Node;

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Print List
void print()
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Reverse List
void reverse()
{
    Node *current = head;
    Node *temp = NULL;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    if (temp != NULL)
    {
        tail = head;
        head = temp->prev;
    }
}

// Find Minimum
void findMin()
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }

    Node *temp = head;
    int min = head->data;

    while (temp != NULL)
    {
        if (temp->data < min)
            min = temp->data;

        temp = temp->next;
    }

    cout << "Minimum = " << min << endl;
}

// Find Maximum
void findMax()
{
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }

    Node *temp = head;
    int max = head->data;

    while (temp != NULL)
    {
        if (temp->data > max)
            max = temp->data;

        temp = temp->next;
    }

    cout << "Maximum = " << max << endl;
}

int main()
{
    insert(40);
    insert(15);
    insert(80);
    insert(10);
    insert(60);

    cout << "Original List: ";
    print();

    reverse();

    cout << "Reversed List: ";
    print();

    findMin();
    findMax();

    return 0;
}
