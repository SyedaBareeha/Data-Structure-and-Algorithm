#include <iostream>
#include <cmath>
using namespace std;

#define SIZE 10

float hashTable[SIZE];

// Hash function (float input)
int hashFunction(float key) {

    // float ko integer form me convert kar rahe hain
    int intKey = (int)(key * 100);  

    return abs(intKey) % SIZE; //abs(intKey) → Negative numbers ke liye safe
                               //% SIZE → Index find karne ke liye modulo lagaya
}



// Insert function
void insert(float key) {

    int index = hashFunction(key);

    // Linear probing agar collision ho
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }

    hashTable[index] = key;
}

// Display function
void display() {

    for (int i = 0; i < SIZE; i++) {
        cout << i << " --> ";

        if (hashTable[i] == -1)
            cout << "Empty";
        else
            cout << hashTable[i];

        cout << endl;
    }
}

int main() {

    // Initialize table
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;
    }

    insert(12.34);
    insert(45.67);
    insert(89.12);
    insert(12.30);

    display();

    return 0;
}
