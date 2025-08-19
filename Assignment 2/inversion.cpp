#include <iostream>
using namespace std;

int main(){
    int invs = 0;
    int arr[10] = {1,54,13,878,2,45,7,5,6,77};
    cout<<"Array"<<endl;
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int j=0;j<9;j++){
        for(int k=j+1;k<10;k++){
            if(arr[k]<arr[j]){
                invs++;
            }
        }
    }
    cout<<"The number of inversions in this array are: "<<invs<<endl;
    return 0;
}