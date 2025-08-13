#include <iostream>
using namespace std;

void multiply(int n, int m, int p, int q){
    if(m!=p){
        cout<<"Number of columns of matrix 2 should be equal to number of rows of matrix 1..."<<endl;
        return;
    }
    int mat1[n][m], mat2[p][q], mat3[n][q];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"Enter element at row "<<i<<" and column "<<j<<": ";
            cin>>mat1[i][j];
        }
    }
    for(int k=0;k<p;k++){
        for(int l=0;l<q;l++){
            cout<<"Enter element at row "<<k<<" and column "<<l<<": ";
            cin>>mat2[k][l];
        }
    }
    for(int a = 0; a < n; ++a) {
        for (int b = 0; b < q; ++b) {
            for (int c = 0; c < m; ++c) { 
                mat3[a][b] += mat1[a][c] * mat2[c][b];
            }
        }
    }

    cout << "Result of multiplication is:" << endl;
    for(int x = 0; x < n; ++x) {
        for(int y = 0; y < q; ++y) {
            cout << mat3[x][y] << " ";
        }
        cout << endl;
    }
    
}
int main(){
    cout<<"Matrix Multiplication"<<endl;
    int n,m,p,q;
    cout<<"Enter the number of rows for matrix 1: ";
    cin>>n;
    cout<<"Enter the number of columns for matrix 1: ";
    cin>>m;
    cout<<"Enter the number of rows for matrix 2: ";
    cin>>p;
    cout<<"Enter the number of columns for matrix 1: ";
    cin>>q;
    multiply(n,m,p,q);
    return 0;
}