#include <iostream>
using namespace std;

int main(){
    int ans=0;
    int arr[10] = {1,1,2,2,2,4,5,5,7,9};
    cout<<"Array"<<endl;
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<9;i++){
        if(arr[i]!=arr[i+1]){
            ans++;
        }
    }
    if(arr[9]!=arr[8]){
        ans++;
    }
    cout<<"The number of distinct elements are: "<<ans<<endl;
    return 0;
}