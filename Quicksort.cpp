#include <iostream>
using namespace std;


int  setPivot(int left, int right, int array[]) {
    int pivInd= (left+right)/2;
    //for first piv 
    while (left<right) {        //left se right tk chale ga
        while (pivInd<right) { //piv se right taak chale ga
            if (array[right]>array[pivInd]) { //agar bara hai tu aglay pe move hujay ga or wo number aisi rahay ga
                right--;
            }else {
                swap(array[pivInd],array[right]);
                pivInd= right;
                break;
            }
        }
        //for right
        while (left<pivInd) {
            if (array[pivInd]>array[left]) {
                left++;
            }else {
                swap(array[pivInd],array[left]);
                pivInd= left;
                break;
            }
        }
    }

    return pivInd;

}


void QuickSort(int array[], int left, int right) {

    if (left<right) {
        int p=setPivot(left,right,array);
        QuickSort(array,left,p-1);
        QuickSort(array,p+1,right);
    }
}
int main() {
    int array[10]={22,92,17,18,11,78,67,52,85,90};
    QuickSort(array,0,9);
    for (int i=0;i<10;i++) {
        cout<<array[i]<<" ";
    }

}

#include <iostream>
#include <stack>
using namespace std;

// Simple partition (clean version)
int partition(int arr[], int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;

    for(int j = left; j < right; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[right]);
    return i + 1;
}

// Iterative QuickSort
void QuickSortIterative(int arr[], int left, int right)
{
    stack<int> st;

    // initial range push
    st.push(left);
    st.push(right);

    while(!st.empty())
    {
        right = st.top(); st.pop();
        left = st.top(); st.pop();

        int p = partition(arr, left, right);

        // left side
        if(p - 1 > left)
        {
            st.push(left);
            st.push(p - 1);
        }

        // right side
        if(p + 1 < right)
        {
            st.push(p + 1);
            st.push(right);
        }
    }
}

int main()
{
    int array[10] = {22, 92, 17, 18, 11, 78, 67, 52, 85, 90};

    QuickSortIterative(array, 0, 9);

    for(int i = 0; i < 10; i++)
        cout << array[i] << " ";

    return 0;
}