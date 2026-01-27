#include <iostream>
using namespace std;

void SelectionSort(int arr[], int size) {
    int min;
    for (int i = 0; i < size; i++) {
        min=i;
        for (int j = i; j < size; j++) {
            if (arr[j] < arr[min]) {
                min=j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

void print(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}
int main() {
    int arr[]= {3,1,4,0,6,7,5};
    SelectionSort(arr, 7);
    print(arr, 7);
}
