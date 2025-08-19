#include <iostream>
using namespace std;

void printSparseMatrix(int mat[][3]) {
    int rows = mat[0][0];
    int cols = mat[0][1];
    
    int iter = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (iter <= mat[0][2] && mat[iter][0] == i && mat[iter][1] == j) {
                cout << mat[iter][2] << "\t";
                iter++;
            } else {
                cout << 0 << "\t";
            }
        }
        cout << endl;
    }
}

void swapRows(int mat[][3], int idx1, int idx2) {
    for (int i = 0; i < 3; ++i) {
        int temp = mat[idx1][i];
        mat[idx1][i] = mat[idx2][i];
        mat[idx2][i] = temp;
    }
}

void transposeSparseMatrix(const int source[][3], int target[][3]) {
    target[0][0] = source[0][1];
    target[0][1] = source[0][0];
    target[0][2] = source[0][2];

    for (int i = 1; i <= source[0][2]; ++i) {
        target[i][0] = source[i][1];
        target[i][1] = source[i][0];
        target[i][2] = source[i][2];
    }

    int num_elements = target[0][2];
    for (int i = 1; i <= num_elements; ++i) {
        for (int j = 1; j <= num_elements - i; ++j) {
            if (target[j][0] > target[j + 1][0] || (target[j][0] == target[j + 1][0] && target[j][1] > target[j + 1][1])) {
                swapRows(target, j, j + 1);
            }
        }
    }
}


int main() {
    int mat1[6][3] = {
        {4, 4, 5},
        {0, 1, 5},
        {1, 2, 2},
        {2, 0, 4},
        {2, 3, 1},
        {3, 1, 3}
    };

    int mat2[6][3] = {
        {4, 4, 5},
        {0, 3, 1},
        {1, 2, 3},
        {2, 1, 6},
        {3, 0, 2},
        {3, 2, 4}
    };

    if (mat1[0][1] != mat2[0][0]) {
        cout << "Matrices cannot be multiplied: Incompatible dimensions." << endl;
        return 1;
    }

    int mat2_T[6][3];
    transposeSparseMatrix(mat2, mat2_T);

    int result[20][3];
    int k = 1;
    int p1 = 1, p2 = 1;

    for (int i = 0; i < mat1[0][0]; ++i) {
        for (int j = 0; j < mat2_T[0][0]; ++j) {
            int sum = 0;
            p1 = 1;
            p2 = 1;

            while (p1 <= mat1[0][2] && mat1[p1][0] < i) p1++;
            while (p2 <= mat2_T[0][2] && mat2_T[p2][0] < j) p2++;

            while (p1 <= mat1[0][2] && mat1[p1][0] == i && p2 <= mat2_T[0][2] && mat2_T[p2][0] == j) {
                if (mat1[p1][1] < mat2_T[p2][1]) {
                    p1++;
                } else if (mat2_T[p2][1] < mat1[p1][1]) {
                    p2++;
                } else {
                    sum += mat1[p1][2] * mat2_T[p2][2];
                    p1++;
                    p2++;
                }
            }
            if (sum != 0) {
                result[k][0] = i;
                result[k][1] = j;
                result[k][2] = sum;
                k++;
            }
        }
    }

    result[0][0] = mat1[0][0];
    result[0][1] = mat2[0][1];
    result[0][2] = k - 1;

    cout << "Matrix 1:" << endl;
    printSparseMatrix(mat1);

    cout << "\nMatrix 2:" << endl;
    printSparseMatrix(mat2);

    cout << "\nResult of Multiplication:" << endl;
    printSparseMatrix(result);

    return 0;
}