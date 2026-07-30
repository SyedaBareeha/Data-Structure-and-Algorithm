#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    float data;
    Node *left;
    Node *right;
};

// Function to create a new node
Node* createNode(float value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert Like Heap (Level Order)
Node* insert(Node* root, float value)
{
    Node* newNode = createNode(value);

    if (root == NULL)
        return newNode;

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if (temp->left == NULL)
        {
            temp->left = newNode;
            return root;
        }
        else
        {
            q.push(temp->left);
        }

        if (temp->right == NULL)
        {
            temp->right = newNode;
            return root;
        }
        else
        {
            q.push(temp->right);
        }
    }

    return root;
}

// Mirror Function
Node* mirror(Node* root)
{
    if (root == NULL)
        return NULL;

    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);

    return root;
}

// Level Order Traversal
void levelOrder(Node* root)
{
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }
}

int main()
{
    Node* root = NULL;

    root = insert(root, 89);
    root = insert(root, 122);
    root = insert(root, 12);
    root = insert(root, 75);
    root = insert(root, 99);
    root = insert(root, 68);

    cout << "Original Tree: ";
    levelOrder(root);

    mirror(root);

    cout << "\nMirror Tree: ";
    levelOrder(root);

    return 0;
}