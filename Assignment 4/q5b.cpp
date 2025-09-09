#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> q1;
    for(int i=1;i<6;i++){
        q1.push(10*i);
        int n = q1.size()-1;
        for(int j=0;j<n;j++){
            q1.push(q1.front());
            q1.pop();
        }
    }
    int m = q1.size();
    for(int k=0;k<m;k++){
        cout<<q1.front()<<" ";
        q1.pop();
    }
    cout<<endl;
    return 0;
}