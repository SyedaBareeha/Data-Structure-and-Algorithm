#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val)
{
    if(root == NULL)
        return new Node(val);

    if(val < root->data)
        root->left = insert(root->left,val);
    else
        root->right = insert(root->right,val);

    return root;
}

void BSTtoArray(Node* root, vector<int>& arr)
{
    if(root == NULL)
        return;

    BSTtoArray(root->left,arr);

    arr.push_back(root->data);

    BSTtoArray(root->right,arr);
}

void preorderBST(Node* root)
{
    if(root == NULL)
        return;

    cout<<root->data<<" ";

    preorderBST(root->left);
    preorderBST(root->right);
}

bool binarySearch(vector<int>& arr,int value)
{
    int low = 0;
    int high = arr.size()-1;

    while(low <= high)
    {
        int mid = low + (high-low)/2;

        if(arr[mid] == value)
            return true;
        else if(value < arr[mid])
            high = mid-1;
        else
            low = mid+1;
    }

    return false;
}

int main()
{
    Node* root=NULL;

    int n;
    cout<<"Enter number of values: ";
    cin>>n;

    cout<<"Enter values:\n";

    for(int i=0;i<n;i++)
    {
        int value;
        cin>>value;
        root=insert(root,value);
    }

    vector<int> arr;

    BSTtoArray(root,arr);

    cout<<"\nArray Contents (Sorted): ";

    for(int x:arr)
        cout<<x<<" ";

    cout<<"\n\nBST Preorder Traversal: ";
    preorderBST(root);

    int key;

    cout<<"\n\nEnter value to search: ";
    cin>>key;

    if(binarySearch(arr,key))
        cout<<"Value Found";
    else
        cout<<"Value Not Found";

    return 0;
}