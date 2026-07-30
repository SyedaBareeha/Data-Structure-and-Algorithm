#include <iostream>
#include <queue>
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

// Level Order Insertion
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

// BFS (Level Order Traversal)
void BFS(Node* root)
{
    if(root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if(temp->left != NULL)
            q.push(temp->left);

        if(temp->right != NULL)
            q.push(temp->right);
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

    cout << "\nBFS Traversal: ";
    BFS(root);

    return 0;
}