#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

// Ye function do sorted parts ko merge karega
void merge(int arr[], int start, int mid, int end)
{
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    int leftArr[leftSize];   // simple fixed size array (for learning)
    int rightArr[rightSize];

    // Left part copy karo
    for(int i = 0; i < leftSize; i++)
        leftArr[i] = arr[start + i];

    // Right part copy karo
    for(int j = 0; j < rightSize; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0;        // left array index
    int j = 0;        // right array index
    int k = start;    // original array index

    // Compare and merge
    while(i < leftSize && j < rightSize)
    {
        if(leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Agar left mein kuch reh gaya
    while(i < leftSize)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Agar right mein kuch reh gaya
    while(j < rightSize)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}


// Ye recursive function hai
void mergeSort(int arr[], int start, int end)
{
    if(start < end)
    {
        int mid = (start + end) / 2;

        mergeSort(arr, start, mid);      // Left half
        mergeSort(arr, mid + 1, end);    // Right half

        merge(arr, start, mid, end);     // Merge them
    }
}


int main()
{
    int arr[] = {8, 3, 5, 4, 7, 6, 2, 1,9,10};
    int size = 10;

    mergeSort(arr, 0, size - 1);

    cout << "Sorted Array:\n";
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}



#include <iostream>
using namespace std;

// Merge function (same as yours)
void merge(int arr[], int start, int mid, int end)
{
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    int leftArr[leftSize];
    int rightArr[rightSize];

    // Copy left part
    for(int i = 0; i < leftSize; i++)
        leftArr[i] = arr[start + i];

    // Copy right part
    for(int j = 0; j < rightSize; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = start;

    // Merge
    while(i < leftSize && j < rightSize)
    {
        if(leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Remaining left
    while(i < leftSize)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Remaining right
    while(j < rightSize)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Iterative Merge Sort
void mergeSortIterative(int arr[], int n)
{
    for(int currSize = 1; currSize < n; currSize *= 2)
    {
        for(int leftStart = 0; leftStart < n - 1; leftStart += 2 * currSize)
        {
            int mid = min(leftStart + currSize - 1, n - 1);
            int rightEnd = min(leftStart + 2 * currSize - 1, n - 1);

            merge(arr, leftStart, mid, rightEnd);
        }
    }
}

// Print function
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function
int main()
{
    int arr[] = {8, 3, 5, 2, 9, 1};
    int n = 6;

    cout << "Before Sorting: ";
    printArray(arr, n);

    mergeSortIterative(arr, n);

    cout << "After Sorting: ";
    printArray(arr, n);

    return 0;
}