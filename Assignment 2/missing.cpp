#include <iostream>
using namespace std;

int arr[7] = {24,25,26,28,29,30,31}, n=7;

void lsearch(){
    cout<<"Finding in linear time"<<endl;
    for(int j=0;j<n-1;j++){
        if(arr[j+1]-arr[j]!=1){
            cout<<"The missing number is "<<arr[j]+1<<endl;
            return;
        }
    }
    cout<<"All the elements are present..."<<endl;
}

void bsearch(){
    cout<<"Using binary search"<<endl;
    int r=n, l=0, ans;
    while(r>=l){
        int mid = (r+l)/2;
        if(arr[mid]-mid!=arr[0]){
            r = mid-1;
        } else{
            l = mid+1;
            ans = mid;
        }
    }
    cout<<"The missing element is "<<arr[ans]+1<<endl;

}

int main(){
    cout<<"Searching for the missing number inside the following array..."<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    lsearch();
    bsearch();
    return 0;
}