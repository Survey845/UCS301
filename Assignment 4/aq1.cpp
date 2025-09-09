#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n;
    queue<string> q;
    q.push("1");
    cout<<"Enter the number till which you want the binary representation: ";
    cin>>n;
    for(int j=0;j<n;j++){
        string s1 = q.front();
        q.pop();
        cout << s1 << "\n";
        string s2 = s1; 
        q.push(s1.append("0"));
        q.push(s2.append("1"));
    }
    return 0;
}