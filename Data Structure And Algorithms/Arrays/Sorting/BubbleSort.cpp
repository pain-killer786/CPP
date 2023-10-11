// Repeatedly swap two adjacent elements if they are in Wrong Order.

#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n) {
    for (int count = 0; count < n - 1; count++) {
        bool swapped = false;
        for (int i = 0; i < n - count - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            // If no swaps were made in a pass, the array is already sorted.
            break;
        }
    }
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter a number: ";
        cin >> arr[i];
    }

    BubbleSort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}