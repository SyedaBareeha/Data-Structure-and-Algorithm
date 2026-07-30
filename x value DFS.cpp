#include<iostream>
#include<queue>
#include<stack>
using namespace std;


struct Node
{
    float data;
    Node* left;
    Node* right;

    Node(float val)
    {
        data = val;
        left = right = NULL;
    }
};


// Insert Node in Binary Tree (Level Order)
void insert(Node* &root, float value)
{
    Node* newNode = new Node(value);

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


// DFS Search (Using Stack)
bool DFS(Node* root, float x)
{
    if(root == NULL)
        return false;


    stack<Node*> st;
    st.push(root);


    while(!st.empty())
    {
        Node* temp = st.top();
        st.pop();


        if(temp->data == x)
            return true;


        // Right first push
        if(temp->right != NULL)
            st.push(temp->right);


        // Left push
        if(temp->left != NULL)
            st.push(temp->left);
    }


    return false;
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


        if(temp->right != NULL)
            st.push(temp->right);


        if(temp->left != NULL)
            st.push(temp->left);
    }
}



int main()
{
    Node* root = NULL;


    int n;
    float value;


    cout<<"Enter number of nodes: ";
    cin>>n;


    cout<<"Enter float values:\n";


    for(int i=0;i<n;i++)
    {
        cin>>value;
        insert(root,value);
    }



    cout<<"\nPreorder Traversal: ";
    preorder(root);



    float x;

    cout<<"\n\nEnter value to search: ";
    cin>>x;



    if(DFS(root,x))
        cout<<"Value Found";

    else
        cout<<"Value Not Found";


    return 0;
}