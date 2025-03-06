#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> & arr , int& iterations) {
  int n = arr.size();
  for (int i = 1; i < n; ++i) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      --j;
      ++iterations;
    }
    arr[j + 1] = key;
  }
}

int main(){
  int n;
  cout << "Enter the number of elements: ";
  cin >> n;

  vector<int> arr(n);
  cout << "Enter the elements: ";
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  int iterations = 0;
  insertionSort(arr, iterations);

  cout << "Sorted array: ";
  for (int i = 0; i < arr.size(); ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;

  cout << "Number of iterations: " << iterations << endl;
  return 0;
}