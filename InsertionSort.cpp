#include <iostream>
using namespace std;

void insertionSort(int a[], int n) {
    int j;
    for (int i = 1; i < n; i++) {
        j=i-1;
        while (j>=0 && a[j]>a[j+1]) {
            swap(a[j], a[j+1]);
            j--;
        }
    }

}
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main() {
 int a[] = {4,1,6,2,8,5,3};
    insertionSort(a, 7);
    printArray(a, 7);
}
