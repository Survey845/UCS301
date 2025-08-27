#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int>nge(n, 0); 
    stack<int>st{};
        for(int i = n-1; i>=0; --i){
            while(!st.empty() && temperatures[st.top()] <= temperatures[i])
                st.pop();
            if(!st.empty())
                nge[i] = st.top()-i; 
            st.push(i);
        }    
    return nge;
}

int main(){
    vector<int> temp = {73,74,75,71,69,72,76,73};
    vector<int> res = dailyTemperatures(temp);

    for (int x : res) {
        cout << x << " ";
    }
    cout<<endl;

    return 0;
}