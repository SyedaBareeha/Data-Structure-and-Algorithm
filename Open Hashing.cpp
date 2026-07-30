#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node hashtable[10];   // Object array (same as yours)

int hashfunction(int value)
{
    return value % 10;
}

void initialize()
{
    for (int i = 0; i < 10; i++)
    {
        hashtable[i].data = -1;   // mark empty
        hashtable[i].next = NULL;
    }
}

void insert(int value)
{
    int index = hashfunction(value);

    // If bucket empty
    if (hashtable[index].data == -1)
    {
        hashtable[index].data = value;
    }
    else
    {
        Node* temp = new Node;
        temp->data = value;
        temp->next = NULL;

        Node* curr = &hashtable[index];

        while (curr->next != NULL)
        {
            curr = curr->next;
        }

        curr->next = temp;
    }
}

void display()
{
    for (int i = 0; i < 10; i++)
    {
        cout << "Index " << i << ": ";

        if (hashtable[i].data == -1)
        {
            cout << "NULL";
        }
        else
        {
            Node* temp = &hashtable[i];

            while (temp != NULL)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL";
        }

        cout << endl;
    }
}

int main()
{
    initialize();

    insert(75);
    insert(23);
    insert(125);
    insert(30);
    insert(76);

    display();
}
