#include <iostream>
using namespace std;

int arr[7] = {64,34,25,12,22,11,90}, n=7;

void bubble(){
    for(int j=0;j<n-1;j++){
        bool swap = false;
        for(int k=0;k<n-j-1;k++){
            if(arr[k]>arr[k+1]){
                arr[k] = arr[k]+arr[k+1];
                arr[k+1] = arr[k]-arr[k+1];
                arr[k] = arr[k]-arr[k+1];
                swap=true;
            }
        }
        if(!swap){
            break;
        }
    }
    cout<<"The sorted array..."<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    cout<<"Sorting the following array using bubble sort..."<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    bubble();
    return 0;
}