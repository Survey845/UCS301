#include <iostream>
using namespace std;

int main(){
    cout<<"Reversing the elements of an array..."<<endl;
    int n;
    cout<<"Enter the length of your array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the element at index "<<i<<": ";
        cin>>arr[i];
    }
    for(int k=0;k<(n/2);k++){
        arr[k] = arr[k]+arr[n-k-1];
        arr[n-k-1] = arr[k]-arr[n-k-1];
        arr[k] = arr[k] - arr[n-k-1];
    }
    cout<<"Reversed array..."<<endl;
    for(int j=0;j<n;j++){
        cout<<arr[j]<<" ";
    }
    cout<<endl;
    return 0;
}