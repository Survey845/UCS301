#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int v){
        val = v;
        next = nullptr;
    }
};

int main(){
    int v,e;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    cout<<"Enter the number of edges: ";
    cin>>e;
    int adj_mat[v][v] = {0};

    for(int m=0;m<v;m++){
        for(int n=0;n<v;n++){
            adj_mat[m][n] = 0;
        }
    }

    for(int i=0;i<e;i++){
        int j,k;
        cout<<"Edge "<<i+1<<endl;
        cout<<"Source: ";
        cin>>j;
        cout<<"Destination: ";
        cin>>k;
        adj_mat[j-1][k-1] = 1;
        adj_mat[k-1][j-1] = 1;
    }
    for(int m=0;m<v;m++){
        for(int n=0;n<v;n++){
            cout<<adj_mat[m][n]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
