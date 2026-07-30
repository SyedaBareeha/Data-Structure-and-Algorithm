#include <iostream>
using namespace std;

// ===== Linked List (store passwords) =====
struct Node {
    string pass;
    int score;
    Node* next;
};

Node* head = NULL;

// ===== Queue (store login attempts) =====
string queue[5];
int front = 0, rear = 0, size = 5;

// enqueue login attempt
void enqueue(string user) {
    if (rear < size) {
        queue[rear++] = user;
    }
}

// show queue
void showQueue() {
    cout << "\nRecent Login Attempts:\n";
    for (int i = front; i < rear; i++) {
        cout << queue[i] << endl;
    }
}

// ===== password check =====
int checkPassword(string p) {
    int score = 0;
    bool u=false, l=false, d=false, s=false;

    if (p.length() >= 8) score++;

    for (char c : p) {
        if (c >= 'A' && c <= 'Z') u = true;
        else if (c >= 'a' && c <= 'z') l = true;
        else if (c >= '0' && c <= '9') d = true;
        else s = true;
    }

    if (u) score++;
    if (l) score++;
    if (d) score++;
    if (s) score++;

    return score;
}

// ===== Linked List insert =====
void addPassword(string p, int score) {
    Node* n = new Node();
    n->pass = p;
    n->score = score;
    n->next = head;
    head = n;
}

// ===== display linked list =====
void showPasswords() {
    Node* temp = head;

    cout << "\nSaved Passwords:\n";

    while (temp != NULL) {
        cout << temp->pass << " -> " << temp->score << endl;
        temp = temp->next;
    }
}

int main() {
    int choice;
    string user, pass;

    while (true) {
        cout << "\n1. Add Password\n2. Show Passwords\n3. Login Attempt\n4. Show Login Queue\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter password: ";
            cin >> pass;

            int score = checkPassword(pass);
            addPassword(pass, score);

            cout << "Score: " << score << endl;
        }
        else if (choice == 2) {
            showPasswords();
        }
        else if (choice == 3) {
            cout << "Enter username: ";
            cin >> user;

            enqueue(user);
            cout << "Login recorded!\n";
        }
        else if (choice == 4) {
            showQueue();
        }
        else {
            break;
        }
    }

    return 0;
}