#include <iostream>
#include <stack>
using namespace std;

// Node Structure
struct Node
{
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// BST Insertion (Without Recursion)
Node* insert(Node* root, int val)
{
    Node* newNode = new Node(val);

    if(root == NULL)
        return newNode;

    Node *curr = root;
    Node *parent = NULL;

    while(curr != NULL)
    {
        parent = curr;

        if(val < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if(val < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

// Postorder Traversal (Without Recursion)
void postOrder(Node* root)
{
    if(root == NULL)
        return;

    stack<Node*> s1, s2;

    s1.push(root);

    while(!s1.empty())
    {
        Node* temp = s1.top();
        s1.pop();

        s2.push(temp);

        if(temp->left != NULL)
            s1.push(temp->left);

        if(temp->right != NULL)
            s1.push(temp->right);
    }

    while(!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

// Descending Order (Without Recursion)
void descending(Node* root)
{
    stack<Node*> st;
    Node* curr = root;

    while(curr != NULL || !st.empty())
    {
        while(curr != NULL)
        {
            st.push(curr);
            curr = curr->right;
        }

        curr = st.top();
        st.pop();

        cout << curr->data << " ";

        curr = curr->left;
    }
}

int main()
{
    Node* root = NULL;

    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nPostorder Traversal (Without Recursion): ";
    postOrder(root);

    cout << "\nDescending Order: ";
    descending(root);

    return 0;
}