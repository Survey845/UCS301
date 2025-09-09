#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> q1, q2;
    for(int i=1;i<6;i++){
        while(!(q1.empty())){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(10*i);
        while(!(q2.empty())){
            q1.push(q2.front());
            q2.pop();
        }
    }
    int n = q1.size();
    for(int j=0;j<n;j++){
        cout<<q1.front()<<" ";
        q1.pop();
    }
    cout<<endl;
    return 0;
}