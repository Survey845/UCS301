#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main(){
    queue<int> students;
    stack<int> sandwich;
    students.push(1);
    students.push(1);
    students.push(0);
    students.push(0);

    sandwich.push(1);
    sandwich.push(0);
    sandwich.push(1);
    sandwich.push(1);

    int counter = 0;
    int n = students.size();
    while(students.size()>0 && counter<n){
        if(students.front() == sandwich.top()){
            students.pop();
            sandwich.pop();
            counter = 0;
        } else{
            int j = students.front();
            students.pop();
            students.push(j);
            counter++;
        }
    }
    if(counter==4){
        cout<<"Students are unable to eat..."<<endl;
    } else{
        cout<<"Queue ended..."<<endl;
    }


}