#include <iostream>
#include <queue>
using namespace std;

struct Node {
    float data;
    Node *left, *right;

    Node(float val) {
        data = val;
        left = right = NULL;
    }
};

// Insert in level order (left to right)
void insert(Node* &root, float value) {
    Node* newNode = new Node(value);

    if (root == NULL) {
        root = newNode;
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        } else
            q.push(temp->left);

        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        } else
            q.push(temp->right);
    }
}

// Search element
bool search(Node* root, float key) {
    if (root == NULL)
        return false;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->data == key)
            return true;

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }

    return false;
}

// Predecessor & Successor in level order
void predecessorSuccessor(Node* root, float key) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    Node* prev = NULL;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr->data == key) {
            cout << "\nPredecessor: ";
            if (prev)
                cout << prev->data;
            else
                cout << "None";

            cout << "\nSuccessor: ";
            if (!q.empty())
                cout << q.front()->data;
            else
                cout << "None";
            return;
        }

        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);

        prev = curr;
    }

    cout << "\nElement not found.";
}

// Count nodes
int countNodes(Node* root) {
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Level Order Display
void levelOrder(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    cout << "\nTree (Level Order): ";

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}

int main() {
    Node* root = NULL;

    int n;
    float value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter float values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insert(root, value);
    }

    levelOrder(root);

    float key;
    cout << "\n\nEnter value to search: ";
    cin >> key;

    if (search(root, key)) {
        cout << "Element Found\n";
        predecessorSuccessor(root, key);
    } else {
        cout << "Element Not Found";
    }

    cout << "\nTotal Nodes: " << countNodes(root) << endl;

    return 0;
}
