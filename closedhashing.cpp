#include <iostream>
using namespace std;

#define SIZE 10

int hashArray[SIZE];   // Ye actual data store karega
bool occupied[SIZE];   // Ye bata raha hai ki slot filled hai ya nahi
bool deleted[SIZE];    // Ye mark karega ki slot pehle delete hua tha

// Function to initialize hash table
void initHashArray() {
    for (int i = 0; i < SIZE; i++) {
        hashArray[i] = 0;     // Default value 0
        occupied[i] = false;  // Sab slots initially empty
        deleted[i] = false;   // Sab slots pehle delete nahi hue
    }
}

// Simple hash function: value ko index me convert karta hai
int hashFunction(int val) {
    return val % SIZE;   // modulo operation se index nikalte hain
}

// Function to insert value in hash table using linear probing
void insertHashArray(int val) {
    int index = hashFunction(val);   // Hash function se start index
    int startIndex = index;          // Loop me pura table check karne ke liye

    // Agar slot empty hai → direct insert
    if (!occupied[index]) {
        hashArray[index] = val;
        occupied[index] = true;
        deleted[index] = false;   // ye ensure karte hain ki delete mark clear ho
        return;
    }

    // Slot full hai → linear probing
    do {
        index = (index + 1) % SIZE;   // next slot check karo circularly

        if (index == startIndex) {    // pura table full hai
            cout << "Hash table is full" << endl;
            return;
        }
    } while (occupied[index]);         // jab tak slot filled hai, aage badho

    // Empty slot mil gaya → insert
    hashArray[index] = val;
    occupied[index] = true;
    deleted[index] = false;
}

// Function to search value in hash table
void searchHashArray(int val) {
    int index = hashFunction(val);  // start index
    int startIndex = index;

    // Jab tak slot filled hai ya delete hua tha
    while (occupied[index] || deleted[index]) {
        if (occupied[index] && hashArray[index] == val) {
            cout << "Found" << endl;
            return;
        }

        index = (index + 1) % SIZE;  // next slot check karo

        if (index == startIndex)      // pura table search ho gaya
            break;
    }

    cout << "Not Found" << endl;
}

// Function to delete value from hash table
void deleteHashArray(int val) {
    int index = hashFunction(val);
    int startIndex = index;

    // Jab tak slot filled ya deleted mark hai
    while (occupied[index] || deleted[index]) {

        // Value mil gayi → delete kar do
        if (occupied[index] && hashArray[index] == val) {
            occupied[index] = false;  // slot empty mark karo
            deleted[index] = true;    // delete mark rakho
            cout << "Deleted" << endl;
            return;
        }

        index = (index + 1) % SIZE;  // next slot check karo

        if (index == startIndex)      // pura table search ho gaya
            break;
    }

    cout << "Not Found" << endl;  // agar value nahi mili
}

// Function to display hash table
void display() {
    cout << "\nIndex\tValue\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << "\t";
        if (!occupied[i])             // agar slot empty hai
            cout << "EMPTY";
        else
            cout << hashArray[i];     // print value
        cout << endl;
    }
}

// Main function
int main() {

    initHashArray();   // table initialize

    // Insert some values
    insertHashArray(1);
    insertHashArray(2);
    insertHashArray(3);
    insertHashArray(4);
    insertHashArray(5);

    // Search values
    searchHashArray(1);
    searchHashArray(2);

    // Delete values
    deleteHashArray(1);
    deleteHashArray(2);

    // Search again after delete
    searchHashArray(2);

    // Insert again to see linear probing
    insertHashArray(3);   // duplicate
    insertHashArray(33);  // collision example (33 % 10 = 3, 3 already filled)

    // Display final hash table
    display();

    return 0;
}
