#include <iostream>
using namespace std;

int mat[50][50], n, m;

void create(){
    cout<<"Enter the number of rows: ";
    cin>>n;
    cout<<"Enter the number of columns: ";
    cin>>m;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<"Enter the element at row "<<i<<" and column "<<j<<": ";
            cin>>mat[i][j];
        }
    }
}

void row_sum(){
    for(int i=0;i<n;i++){
        int ans = 0;
        for(int j=0;j<m;j++){
            ans+=mat[i][j];
        }
        cout<<"The sum of row "<<i<<" is: "<<ans<<endl;
    }
}
void col_sum(){
    for(int i=0;i<m;i++){
        int ans = 0;
        for(int j=0;j<n;j++){
            ans+=mat[j][i];
        }
        cout<<"The sum of column "<<i<<" is: "<<ans<<endl;
    }
}
int main(){
    create();
    row_sum();
    col_sum();
    return 0;
}