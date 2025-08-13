#include <iostream>
using namespace std;

int mat[50][50], trans[50][50], n, m;
void create(){
    cout<<"Enter the number of rows for matrix: ";
    cin>>n;
    cout<<"Enter the number of columns for matrix: ";
    cin>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"Enter the element at row "<<i<<" and column "<<j<<": ";
            cin>>mat[i][j];
        }
    }
    for(int l=0;l<n;l++){
        for(int p=0;p<m;p++){
            cout<<mat[l][p]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
    

void transpose(){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            trans[i][j] = mat[j][i];
        }
    }
    for(int l=0;l<m;l++){
        for(int p=0;p<n;p++){
            cout<<trans[l][p]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    create();
    transpose();
    return 0;

}