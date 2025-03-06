#include <iostream>
using namespace std;

void countingSort(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    int count[maxVal + 1] = {0};
    int sorted[n];

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= maxVal; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
        sorted[--count[arr[i]]] = arr[i];

    for (int i = 0; i < n; i++)
        arr[i] = sorted[i];
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
