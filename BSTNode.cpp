#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* root = NULL;

// 🔹 Insert (Recursive)
Node* insert(Node* curr, int value)
{
    if(curr == NULL)
    {
        Node* temp = new Node();
        temp->data = value;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    if(value < curr->data)
        curr->left = insert(curr->left, value);
    else if(value > curr->data)
        curr->right = insert(curr->right, value);

    return curr;
}

// 🔹 Search (Recursive)
Node* searchNode(Node* curr, int value)
{
    if(curr == NULL || curr->data == value)
        return curr;

    if(value < curr->data)
        return searchNode(curr->left, value);
    else
        return searchNode(curr->right, value);
}

// 🔹 Inorder (Left Root Right)
void inorder(Node* curr)
{
    if(curr != NULL)
    {
        inorder(curr->left);
        cout << curr->data << " ";
        inorder(curr->right);
    }
}

// 🔹 Preorder (Root Left Right)
void preorder(Node* curr)
{
    if(curr != NULL)
    {
        cout << curr->data << " ";
        preorder(curr->left);
        preorder(curr->right);
    }
}

// 🔹 Postorder (Left Right Root)
void postorder(Node* curr)
{
    if(curr != NULL)
    {
        postorder(curr->left);
        postorder(curr->right);
        cout << curr->data << " ";
    }
}

int main()
{
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 3);
    root = insert(root, 7);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << "\n";

    // Search Test
    Node* result = searchNode(root, 7);

    if(result != NULL)
        cout << "Value Found: " << result->data << endl;
    else
        cout << "Value Not Found" << endl;

    return 0;
}