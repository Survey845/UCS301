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

    Node* adj_list[v];

    for(int i=0; i<v; i++){
        adj_list[i] = nullptr;
    }

    for(int l=0; l<v; l++){
        for(int n=0; n<v; n++){
            if(adj_mat[l][n] == 1){
                Node* new_neighbor = new Node(n+1);
                new_neighbor->next = adj_list[l];
                adj_list[l] = new_neighbor;
            }
        }
    }

    for(int i=0; i<v; i++){
        cout << "Vertex " << (i+1) << ": ";
        Node* temp = adj_list[i];
        while(temp != nullptr){
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    for(int l=0;l<v;l++){

    }
    return 0;
}
