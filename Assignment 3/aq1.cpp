#include <iostream>
using namespace std;

int main(){
    int arr[8] = {1,4,6,2,0,6,8,9};
    for(int i=0;i<8;i++){
        for(int j=(i-1); j>=0;j--){
            if(arr[j]<arr[i]){
                cout<<"The nearest smaller element for "<<arr[i]<<" is: "<<arr[j]<<endl;
                break;
            }
        }
    }
    return 0;
}