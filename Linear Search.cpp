#include <iostream>
using namespace std;

void LinearSearch(int array[],int size, int target) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (array[i]==target) {
            cout << "FOUND at index "<<i ;
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "NOT FOUND" << endl;
    }
}
int main() {

   int array[] = {1,2,3,4,5,6,7,8,9};
    LinearSearch(array,9,6);
}
