#include <iostream>
using namespace std;

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout<<"Tri-Diagonal matrix (by row)..."<<endl;
    int counter = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if (abs(i-j)<=1){
                cout<<arr[counter]<<" ";
                counter++;
            } else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}