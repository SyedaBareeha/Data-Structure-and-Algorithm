#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        data = value;
        left = right= NULL;
        height = 0;
    }
};

int getHeight(Node* root) {
    if (root == NULL) return -1;
    return root->height;
}
int getBalance(Node* root) {
    if (root == NULL) return 0;
    return getHeight(root->left) - getHeight(root->right);
}
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    return x;
}
Node* insert(Node* root, int key) {

    if (root == NULL) {
        return new Node(key);
    }

    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // balance factor
    int bf = getBalance(root);

    // LL
    if (bf > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // RR
    if (bf < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // LR
    if (bf > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL
    if (bf < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
int main() {
    Node* root = NULL;

    int arr[] = {120, 110, 150, 130, 140, 146, 136, 134, 138, 160, 154, 156, 132, 125, 128};

    for (int i = 0; i < 15; i++) {
        root = insert(root, arr[i]);
    }

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}