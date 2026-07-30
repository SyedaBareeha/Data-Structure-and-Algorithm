#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    int j;
    for (int i = 1; i < n; i++) {
        j=i-1;
        while (j>=0 && arr[j]>arr[j+1]) {
            swap(arr[j], arr[j+1]);
            j--;
        }
    }

}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
 int arr[] = {4,1,6,2,8,5,3};
    insertionSort(arr, 7);
    printArray(arr, 7);
}