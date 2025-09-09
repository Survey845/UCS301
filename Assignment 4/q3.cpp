#include <iostream>
#include <queue>
using namespace std;



int main(){
    queue<int> q1, q2;
    q1.push(4);
    q1.push(7);
    q1.push(11);
    q1.push(20);
    q1.push(5);
    q1.push(9);
    int n = q1.size();
    for(int i=0;i<(n/2);i++){
        q2.push(q1.front());
        q1.pop();
    }
    for(int j=0;j<(n/2);j++){
        q1.push(q2.front());
        q2.pop();
        q1.push(q1.front());
        q1.pop();
    }
    for(int k=0;k<n;k++){
        cout<<q1.front()<<" ";
        q1.pop();
    }
    cout<<endl;
}