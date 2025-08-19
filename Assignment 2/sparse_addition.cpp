#include <iostream>
using namespace std;

void printSparseMatrix(int mat[][3]) {
    int rows = mat[0][0];
    int cols = mat[0][1];
    
    int iter = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (iter <= mat[0][2] && mat[iter][0] == i && mat[iter][1] == j) {
                cout << mat[iter][2] << " ";
                iter++;
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int mat1[6][3] = {
        {5, 5, 5},
        {0, 2, 3},
        {1, 1, 5},
        {2, 3, 2},
        {3, 0, 4},
        {4, 4, 1}
    };

    int mat2[6][3] = {
        {5, 5, 5},
        {0, 3, 2},
        {1, 1, 2},
        {2, 2, 6},
        {3, 0, 1},
        {4, 1, 9}
    };

    if (mat1[0][0] != mat2[0][0] || mat1[0][1] != mat2[0][1]) {
        cout << "Matrices cannot be added as they have different dimensions." << endl;
        return 1;
    }

    int result[11][3];
    
    int i = 1, j = 1; 
    int k = 1; 

    while (i <= mat1[0][2] && j <= mat2[0][2]) {
        if (mat1[i][0] < mat2[j][0] || (mat1[i][0] == mat2[j][0] && mat1[i][1] < mat2[j][1])) {
            result[k][0] = mat1[i][0];
            result[k][1] = mat1[i][1];
            result[k][2] = mat1[i][2];
            i++;
            k++;
        }
        else if (mat2[j][0] < mat1[i][0] || (mat2[j][0] == mat1[i][0] && mat2[j][1] < mat1[i][1])) {
            result[k][0] = mat2[j][0];
            result[k][1] = mat2[j][1];
            result[k][2] = mat2[j][2];
            j++;
            k++;
        }
        else {
            result[k][0] = mat1[i][0];
            result[k][1] = mat1[i][1];
            result[k][2] = mat1[i][2] + mat2[j][2];
            i++;
            j++;
            k++;
        }
    }

    while (i <= mat1[0][2]) {
        result[k][0] = mat1[i][0];
        result[k][1] = mat1[i][1];
        result[k][2] = mat1[i][2];
        i++;
        k++;
    }

    while (j <= mat2[0][2]) {
        result[k][0] = mat2[j][0];
        result[k][1] = mat2[j][1];
        result[k][2] = mat2[j][2];
        j++;
        k++;
    }

    result[0][0] = mat1[0][0];
    result[0][1] = mat1[0][1];
    result[0][2] = k - 1;

    cout << "Matrix 1:" << endl;
    printSparseMatrix(mat1);

    cout << "\nMatrix 2:" << endl;
    printSparseMatrix(mat2);

    cout << "\nResult of Addition:" << endl;
    printSparseMatrix(result);

    return 0;
}
