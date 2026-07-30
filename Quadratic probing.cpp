#include <iostream>
using namespace std;

#define SIZE 10
int hashArray[SIZE];
bool occupied[SIZE];
bool deleted[SIZE];

void initHashArray() {
    for (int i = 0; i < SIZE; i++) {
        hashArray[i] = 0;
        occupied[i] = false;
        deleted[i] = false;
    }
}

int hashFunction(int val) {
    return val % SIZE;
}

// 🔹 INSERT (Quadratic Probing)
void insertHashArray(int val) {
    int index = hashFunction(val);
    int startIndex = index;
    int i = 1;

    if (!occupied[index]) {
        hashArray[index] = val;
        occupied[index] = true;
        return;
    }

    while (i < SIZE) {
        index = (startIndex + i * i) % SIZE;

        if (!occupied[index]) {
            hashArray[index] = val;
            occupied[index] = true;
            return;
        }
        i++;
    }

    cout << "Hash table is full" << endl;
}

// 🔹 SEARCH (Quadratic Probing)
void searchHashArray(int val) {
    int index = hashFunction(val);
    int startIndex = index;
    int i = 1;

    if (occupied[index] && hashArray[index] == val) {
        cout << "Found at index: " << index << endl;
        return;
    }

    while (i < SIZE) {
        index = (startIndex + i * i) % SIZE;

        if (occupied[index] && hashArray[index] == val) {
            cout << "Found at index: " << index << endl;
            return;
        }

        if (!occupied[index] && !deleted[index])
            break;

        i++;
    }

    cout << "Not Found" << endl;
}

// 🔹 DELETE (Quadratic Probing)
void deleteHashArray(int val) {
    int index = hashFunction(val);
    int startIndex = index;
    int i = 1;

    if (occupied[index] && hashArray[index] == val) {
        occupied[index] = false;
        deleted[index] = true;
        cout << "Deleted" << endl;
        return;
    }

    while (i < SIZE) {
        index = (startIndex + i * i) % SIZE;

        if (occupied[index] && hashArray[index] == val) {
            occupied[index] = false;
            deleted[index] = true;
            cout << "Deleted" << endl;
            return;
        }

        if (!occupied[index] && !deleted[index])
            break;

        i++;
    }

    cout << "Not Found" << endl;
}

// 🔹 DISPLAY
void display() {
    cout << "\nIndex\tValue\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << "\t";
        if (!occupied[i])
            cout << "EMPTY";
        else
            cout << hashArray[i];
        cout << endl;
    }
}

int main() {
    initHashArray();

    insertHashArray(1);
    insertHashArray(2);
    insertHashArray(3);
    insertHashArray(4);
    insertHashArray(5);

    searchHashArray(1);
    searchHashArray(2);

    deleteHashArray(1);
    deleteHashArray(2);

    searchHashArray(2);

    insertHashArray(3);
    insertHashArray(33);

    display();
}