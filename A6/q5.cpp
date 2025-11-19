#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int value){
        val = value;
    }
};

class CLL{
    Node* head;
    int count;
public:
    CLL(){
        head=nullptr;
    }

    void insertBegin(int value){
        Node* newNode = new Node(value);
        if(head==nullptr){
            head = newNode;
            newNode->next=newNode;
        } else{
            Node* cur = head;
            while(cur->next!=head){
                cur = cur->next;
            }
            cur->next=newNode;
            newNode->next=head;
            head=newNode;
        }
    }

    bool isCircular(){
        Node* cur = head;
        while(cur->next!=head && cur->next!=nullptr){
            cur=cur->next;
        }
        if(cur->next==head){
            return true;
        } else{
            return false;
        }
    }
};

int main(){
    CLL cll;
    cll.insertBegin(1);
    cll.insertBegin(2);
    if(cll.isCircular()){
        cout<<"True"<<endl;
    } else{
        cout<<"False"<<endl;
    }
}
