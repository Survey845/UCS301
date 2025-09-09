#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    queue<char> q1, q2;
    int alpha[26] = {0};
    string quest = "aabbcdefffc";
    for(int m=0;m<quest.size();m++){
        q1.push(quest[m]);
    }
    int n = q1.size();
    for(int i=0;i<n;i++){
        q2.push(q1.front());
        alpha[q1.front()-97]++;
        q1.pop();
    }
    for(int j=0;j<n;j++){
        if(alpha[q2.front()-97]==1){
            cout<<q2.front()<<endl;
            break;
        } else{
            q2.pop();
        }
    }
    return 0;
}