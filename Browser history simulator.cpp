#include <iostream>
#include <string>
using namespace std;

#define SIZE 50

struct Stack
{
    string arr[SIZE];
    int top;

    Stack()
    {
        top = -1;
    }

    void push(string data)
    {
        if(top == SIZE-1)
        {
            cout<<"Stack Overflow\n";
            return;
        }

        arr[++top] = data;
    }

    string pop()
    {
        if(top == -1)
            return "";

        return arr[top--];
    }

    bool empty()
    {
        return top == -1;
    }

    void display()
    {
        if(top == -1)
        {
            cout<<"No History\n";
            return;
        }

        for(int i=top; i>=0; i--)
        {
            cout<<arr[i]<<endl;
        }
    }
};


int main()
{
    Stack backStack;
    Stack forwardStack;

    string current = "Home";

    int choice;
    string website;


    while(true)
    {
        cout<<"   BROWSER HISTORY SYSTEM\n";

        cout<<"Current Page: "<<current<<endl;

        cout<<"\n1. Visit Website";
        cout<<"\n2. Go Back";
        cout<<"\n3. Go Forward";
        cout<<"\n4. Show History";
        cout<<"\n5. Exit";

        cout<<"\n\nEnter Choice: ";
        cin>>choice;


        switch(choice)
        {

        case 1:
            cout<<"Enter Website: ";
            cin>>website;

            // current page back history mein save
            backStack.push(current);

            current = website;

            // new page open hone par forward clear
            forwardStack = Stack();

            cout<<"Opened: "<<current<<endl;

            break;


        case 2:

            if(backStack.empty())
            {
                cout<<"No Previous Page\n";
            }
            else
            {
                forwardStack.push(current);

                current = backStack.pop();

                cout<<"Back to: "<<current<<endl;
            }

            break;



        case 3:

            if(forwardStack.empty())
            {
                cout<<"No Forward Page\n";
            }
            else
            {
                backStack.push(current);

                current = forwardStack.pop();

                cout<<"Forward to: "<<current<<endl;
            }

            break;

        case 4:

            cout<<"\nBack History:\n";
            backStack.display();

            cout<<"\nForward History:\n";
            forwardStack.display();

            break;

        case 5:
            cout<<"Browser Closed...";
            return 0;

        default:
            cout<<"Invalid Choice";
        }
    }
    return 0;
}