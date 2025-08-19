#include <iostream>
using namespace std;

int main(){
    int mat[4] = {1,2,3,4};
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(i==j){
                cout<<mat[i]<<" ";
            } else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}