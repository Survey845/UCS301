#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool canSort(vector<int>& A) {
    int N = A.size();
    stack<int> S;
    int next_num = 1;

    for (int i = 0; i < N; i++) {
        while (!S.empty() && S.top() == next_num) {
            S.pop();
            next_num++;
        }

        if (A[i] == next_num) {
            next_num++;
        } else if (!S.empty() && A[i] > S.top()) {
            return false;
        } else {
            S.push(A[i]);
        }
    }

    return true;
}

int main() {
    int T;
    cout<<"Enter the number of test cases: ";
    cin >> T;

    while (T--) {
        int N;
        cout<<"Enter the number of elements: ";
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cout<<"Enter the element at index "<<i<< ": ";
            cin >> A[i];
        }

        if (canSort(A)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}