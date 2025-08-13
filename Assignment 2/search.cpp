#include <iostream>
using namespace std;

int arr[10] = {6,4,78,43,2,9,10,0,4,6}, n=10;
int bsort[10], lsort[10];
void lsearch(){
    int el;
    cout<<"Performing linear search..."<<endl;
    cout<<"Enter the element to search for: ";
    cin>>el;
    for(int j=0;j<n;j++){
        if(arr[j] == el){
            cout<<"The element is at index "<<j<<endl;
            return;
        }
    }
    cout<<"The element does not exist in this array..."<<endl;
}

void bsearch(){
    int el,r,l;
    cout<<"Performing binary search..."<<endl;
    cout<<"Enter the element to search for: ";
    cin>>el;
    r = n-1;
    l = 0;
    while(r>=l){
        int mid = (r+l)/2;
        if(el==arr[mid]){
            cout<<"The element is at index "<<mid<<endl;
            return;
        } else if(el>arr[mid]){
            r = mid;
        } else{
            l = mid;
        }
    }

}
int main(){
    cout<<"Sorting the following array using binary and linear search!"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    lsearch();
    bsearch();
    return 0;
}