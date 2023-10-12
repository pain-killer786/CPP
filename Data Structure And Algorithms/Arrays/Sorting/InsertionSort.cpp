//Insert an element from unsorted array to its correct position in sorted array

#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position*/
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() 
{
    vector<int> arr;
    int n, num;

    cout<<"Enter the number of elements: ";
    cin>>n;

    cout<<"Enter the elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin>>num;
        arr.push_back(num);
    }

    insertionSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout <<endl;

    return 0;
}