#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node
{
    float data;
    Node *left, *right;

    Node(float val)
    {
        data = val;
        left = right = NULL;
    }
};

// Insert in Level Order (Binary Tree)
void insert(Node* &root, float val)
{
    Node* newNode = new Node(val);

    if(root == NULL)
    {
        root = newNode;
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp->left == NULL)
        {
            temp->left = newNode;
            return;
        }
        else
            q.push(temp->left);

        if(temp->right == NULL)
        {
            temp->right = newNode;
            return;
        }
        else
            q.push(temp->right);
    }
}

// Preorder Traversal Without Recursion
void preorder(Node* root)
{
    if(root == NULL)
        return;

    stack<Node*> st;
    st.push(root);

    while(!st.empty())
    {
        Node* temp = st.top();
        st.pop();

        cout << temp->data << " ";

        // Right pehle push karo
        if(temp->right != NULL)
            st.push(temp->right);

        // Left baad me push karo
        if(temp->left != NULL)
            st.push(temp->left);
    }
}

int main()
{
    Node* root = NULL;

    int n;
    float value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter float values:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> value;
        insert(root, value);
    }

    cout << "\nPreorder Traversal (Without Recursion): ";
    preorder(root);

    return 0;
}