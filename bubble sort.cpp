#include <iostream>
using namespace std;

void bubbleSort(int array[], int size) {
    int swaping=0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i-1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                swaping++;
            }
        }
    }
    if (swaping == 0) {
        cout<<"Array was already sorted"<<endl;
    }

}
void bubbleSortInReverse(int array[], int size) {
    int swaping=0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i-1; j++) {
            if (array[j] < array[j + 1]) {
                swap(array[j], array[j + 1]);
                swaping++;
            }
        }
    }
    if (swaping == 0) {
        cout<<"Array was already in reverse order"<<endl;
    }
}
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
int main() {
    int array[]={5,4,1,2,3,6};

    bubbleSort(array,6);
    printArray(array,6);

    bubbleSortInReverse(array, 6);
    printArray(array,6);

}
