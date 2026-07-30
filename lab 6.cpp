
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node {
    string data;
    Node *left, *right;

    Node(string val) {
        data = val;
        left = right = NULL;
    }
};

// Insert in level order
void insert(Node* &root, string value) {
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

// Level Order Display
void display(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

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

// Mirror Image
void mirror(Node* root) {
    if (root == NULL)
        return;

    swap(root->left, root->right);

    mirror(root->left);
    mirror(root->right);
}

// Predecessor & Successor
void predecessorSuccessor(Node* root, string key) {
    queue<Node*> q;
    q.push(root);

    Node* prev = NULL;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr->data == key) {
            cout << "Predecessor: ";
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

    cout << "Element not found.\n";
}

// Find Level
int level(Node* root, string key, int l) {
    if (root == NULL)
        return -1;

    if (root->data == key)
        return l;

    int left = level(root->left, key, l + 1);
    if (left != -1)
        return left;

    return level(root->right, key, l + 1);
}

// Height of Node
int height(Node* root) {
    if (root == NULL)
        return -1;

    return 1 + max(height(root->left), height(root->right));
}

Node* findNode(Node* root, string key) {
    if (root == NULL)
        return NULL;

    if (root->data == key)
        return root;

    Node* left = findNode(root->left, key);
    if (left)
        return left;

    return findNode(root->right, key);
}

int main() {
    Node* root = NULL;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    string value;

    cout << "Enter string values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insert(root, value);
    }

    cout << "\nOriginal Tree:\n";
    display(root);

    mirror(root);

    cout << "\n\nMirror Tree:\n";
    display(root);

    string key;
    cout << "\n\nEnter element: ";
    cin >> key;

    predecessorSuccessor(root, key);

    int lv = level(root, key, 0);
    if (lv != -1)
        cout << "\nLevel: " << lv;
    else
        cout << "\nElement not found.";

    Node* node = findNode(root, key);

    if (node)
        cout << "\nHeight: " << height(node);

    return 0;
}
