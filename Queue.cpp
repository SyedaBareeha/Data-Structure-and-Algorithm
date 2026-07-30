    #include <iostream>
    using namespace std;

    struct Node {
        int data;
        Node* next;
    };
    Node* front = nullptr;
    Node* rear = nullptr;

    void Enqueue(int value) {
      Node* temp = new Node();
        temp->data = value;
        temp->next = nullptr;

        if (rear == nullptr && front == nullptr) {
           front=  rear = temp;
        }else {
            rear->next = temp;
            rear = temp;
        }
        cout<<value<<"Inserted at Queue"<<endl;
    }

void Dequeue() {
    if (front ==nullptr) {
        cout<<"Can't Dequeue Queue is empty"<<endl;
        return;
    }
        Node* temp = front;
        cout<<front->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        cout<<"Dequeued from Queue"<<endl;
}

void display() {
        if (front == nullptr) {
            cout<<"Can't display Queue is empty"<<endl;
            return;
        }else {
            Node* temp = front;
            while (temp != nullptr) {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
  }
int main() {

        Dequeue();
        Enqueue(1);
        Enqueue(2);
        Enqueue(3);
        Enqueue(4);
        Enqueue(5);
        Dequeue();
        Dequeue();
        Dequeue();
        Dequeue();
        Dequeue();
        Dequeue();
        Enqueue(7);
        Dequeue();
        display();

}