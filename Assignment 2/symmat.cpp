#include <iostream>
using namespace std;

int main(){
    cout<<"Symmetric Matrix"<<endl;
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int counter1 = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if (i >= j) {
                int index = (i * (i + 1) / 2) + j;
                cout << arr[index] << "\t";
            } else {
                int index = (j * (j + 1) / 2) + i;
                cout << arr[index] << "\t";
            }
        }
        cout<<endl;
    }
    return 0;
}