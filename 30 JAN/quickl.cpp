#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high, int& count, int& loop) {
    int pivot = arr[low];
    int i = low + 1;

    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
            count++;
        }
        loop++;
    }
    cout<<"pivot element " << pivot <<endl;
    swap(arr[low], arr[i - 1]);
    return i - 1;
}

void quicksort(vector<int>& arr, int low, int high, int& count, int& loop) {
    if (low < high) {
        int pi = partition(arr, low, high, count, loop);
        quicksort(arr, low, pi - 1, count, loop);
        quicksort(arr, pi + 1, high, count, loop);
    }
}

int main() {
    vector<int> arr = {10,20,30,40,50,60,70,80,90,100};
    int n = arr.size();
    int count = 0;
    int loop = 0;
    quicksort(arr, 0, n - 1, count, loop);
    
    cout << "Number of Swaps: " << count << endl;
    cout << "Number of loops: " << loop << endl;
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}