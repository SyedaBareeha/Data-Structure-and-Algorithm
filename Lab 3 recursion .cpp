#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *child[4];

    Node(int x)
    {
        data = x;
        for(int i=0;i<4;i++)
            child[i]=NULL;
    }
};

Node* buildTree(int arr[], int start, int end)
{
    if(start > end)
        return NULL;

    int n = end - start + 1;

    // Median index
    int mid = start + n/2;

    Node *root = new Node(arr[mid]);

    // Divide into four parts
    int m1 = start + (mid-start)/2;
    int m2 = mid + 1 + (end-mid)/2;

    // S1
    if(start <= mid-1)
        root->child[0] = buildTree(arr, start, mid-1);

    // S2 (same recursion on left half)
    if(mid+1 <= end)
        root->child[1] = buildTree(arr, mid+1, end);

    return root;
}

void preorder(Node *root)
{
    if(root==NULL)
        return;

    cout<<root->data<<" ";

    for(int i=0;i<4;i++)
        preorder(root->child[i]);
}

int height(Node *root)
{
    if(root==NULL)
        return 0;

    int h=0;

    for(int i=0;i<4;i++)
    {
        int x=height(root->child[i]);
        if(x>h)
            h=x;
    }

    return h+1;
}

int main()
{
    int arr[]={22,44,75,90,92,99,110,112,125,130,131};

    int n=sizeof(arr)/sizeof(arr[0]);

    Node *root=buildTree(arr,0,n-1);

    cout<<"Preorder Traversal:\n";
    preorder(root);

    cout<<"\n\nHeight = "<<height(root);

    return 0;
}
