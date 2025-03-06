#include <iostream>
using namespace std;

void printCount(int count) {
    cout << "Number of iterations: " << count << endl;
}

void bubbleSort(int arr[], int n) {
    int iterationCount = 0;
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            iterationCount++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            cout << "Best case" << endl;
            break;
        }
    }
    printCount(iterationCount);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original Array: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}