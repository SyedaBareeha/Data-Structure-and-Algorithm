#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* root = NULL;

Node* insert(Node* curr, int value){

    if(curr == NULL){
        Node* temp = new Node();
        temp->data = value;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    if(value < curr->data){
        curr->left = insert(curr->left, value);
    }
    else if(value > curr->data){
        curr->right = insert(curr->right, value);
    }

    return curr;

}

Node* searchNode(Node* curr, int value)
{
    if(curr == NULL || curr->data == value)
        return curr;

    if(value < curr->data)
        return searchNode(curr->left, value);
    else
        return searchNode(curr->right, value);
}

// Node*minvalue(Node*curr){
//     while(curr->left!=NULL)
// }
void preorder(Node* curr)
{
    if(curr != NULL)
    {
        cout << curr->data << " ";  
        preorder(curr->left);      
        preorder(curr->right);     
    }
}


void postorder(Node*curr){
    if (curr!=NULL){
        postorder(curr->right);
        postorder(curr->left);
        cout<< curr->data <<" ";
    }
}
void inorder(Node* curr)
{
    if(curr != NULL)
    {
        inorder(curr->left);     
        cout << curr->data << " ";  
        inorder(curr->right);    
    }
}

Node*deletenode(Node*curr,int value){
    if (curr==NULL)
    return NULL;

}

int main()
{
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 3);
    root = insert(root, 7);

    cout << "Nodes inserted successfully!" << endl;

    searchNode(root, 7);
    searchNode(root, 15);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

     cout << "\nPostorder: ";
    preorder(root);

    return 0;
}













