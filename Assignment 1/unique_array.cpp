#include <iostream>
#include <unordered_map>
using namespace std;

void remove_duplicates(int arr[], int n){
    unordered_map<int, int> umap;
    for(int j=0;j<n;j++){
        if(umap[arr[j]] >= 1){
            for(int k=j;k<n;k++){
                arr[k] = arr[k+1];

            }
            n-=1;
        } else{
            umap[arr[j]] = 1;
        }
    }
    for(int d=0;d<n;d++){
        cout<<arr[d]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter the length of your array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter element at index "<<i<<": ";
        cin>>arr[i];
    }
    cout<<"Removing duplicates..."<<endl;
    remove_duplicates(arr, n);

    return 0;
}