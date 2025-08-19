#include <iostream>
using namespace std;

void swapRows(int mat[6][3], int idx1, int idx2) {
    int temp_row = mat[idx1][0];
    int temp_col = mat[idx1][1];
    int temp_val = mat[idx1][2];

    mat[idx1][0] = mat[idx2][0];
    mat[idx1][1] = mat[idx2][1];
    mat[idx1][2] = mat[idx2][2];

    mat[idx2][0] = temp_row;
    mat[idx2][1] = temp_col;
    mat[idx2][2] = temp_val;
}

int main(){
    cout<<"Sparse Matrix functions"<<endl;
    int mat[6][3] = {{6,6,5},{0,3,2},{0,4,2},{1,3,1},{3,3,8},{5,5,7}};
    int iter1 = 1;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(mat[iter1][0] == i && mat[iter1][1] == j){
                cout<<mat[iter1][2]<<" ";
                iter1++;
            } else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }

    cout<<"Transpose of sparse matrix..."<<endl;
    for(int t=1;t<6;t++){
        mat[t][0] = mat[t][0] + mat[t][1];
        mat[t][1] = mat[t][0] - mat[t][1];
        mat[t][0] = mat[t][0] - mat[t][1];
    }
    
    int num_elements = mat[0][2]; 
    for (int a = 1; a <= num_elements - 1; a++) {
        for (int b = 1; b <= num_elements - a; b++) {
            bool shouldSwap = mat[b][0] > mat[b + 1][0];

            if (!shouldSwap && mat[b][0] == mat[b + 1][0]) {
                if (mat[b][1] > mat[b + 1][1]) {
                    shouldSwap = true;
                }
            }
            
            if (shouldSwap) {
                swapRows(mat, b, b + 1);
            }
        }
    }

    cout<<"The transpose matrix looks like..."<<endl;
    int iter2 = 1;
    for(int p=0;p<6;p++){
        for(int q=0;q<6;q++){
            if(mat[iter2][0] == p && mat[iter2][1] == q){
                cout<<mat[iter2][2]<<" ";
                iter2++;
            } else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}