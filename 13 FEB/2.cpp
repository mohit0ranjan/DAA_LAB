#include <iostream>
using namespace std;

void findMarksWithAtLeastTwoGreater(int arr[], int n) {
    
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    
    for (int i = 0; i < n-2; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {50, 40, 10, 20, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    findMarksWithAtLeastTwoGreater(arr, n);
    return 0;
}