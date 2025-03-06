#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int findKthLargest(vector<int>& arr, int k) {
    bubbleSort(arr);
    return arr[k - 1];
}

int main() {
    vector<int> arr = {5, 1, 8, 2, 6, 3};
    int k = 4;
    int kthLargest = findKthLargest(arr, k);
    cout << "The " << k << "th largest element is " << kthLargest << endl;
    return 0;
}
