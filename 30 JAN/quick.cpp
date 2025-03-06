#include <iostream>
#include <vector>
using namespace std;    

int partition(vector<int>& arr,int low , int high,int& count,int& loop){
    int pivot = arr[high];
    int i=low-1;

    for (int j=low ; j <= high-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
            count ++;
        }
        loop++;
    }

    swap(arr[i+1],arr[high]);
    return i+1;
}

void quicksort(vector<int>& arr,int low , int high,int& count,int& loop){
    if (low<high){
        int pi = partition(arr,low,high,count,loop);    
        quicksort(arr,low,pi-1,count,loop);
        quicksort(arr,pi+1,high,count,loop);
    }
}

int main (){
    vector <int> arr={1,2,3,4,5};
    int n = arr.size();
    int count = 0;
    int loop = 0;
    quicksort(arr,0,n-1,count,loop);
    cout<<"Number of Swaps: "<<count<<endl;
    cout<<"Number of loops: "<<loop<<endl;
    cout<<"Sorted array: ";
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}