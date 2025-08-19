#include <iostream>
using namespace std;

int main(){
    cout<<"Lower Triangle Matrix"<<endl;
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int counter = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i<j){
                cout<<0<<" ";
            } else{
                cout<<arr[counter]<<" ";
                counter++;
            }
        }
        cout<<endl;
    }
    return 0;
}