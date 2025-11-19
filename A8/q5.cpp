#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<n && arr[left]>arr[largest]){
        largest = left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest = right;
    }

    if(largest!=i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr){
    int n = arr.size();

    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }

    for(int j=n-1;j>0;j--){
        swap(arr[0],arr[j]);
        heapify(arr,j,0);
    }
}

int main(){
    vector<int> arr = {1,4,7,5,6,8,2};
    heapSort(arr);

    for (int k=0;k<arr.size();++k)
        cout << arr[k] << " ";
    cout<<endl;
    return 0;
}
