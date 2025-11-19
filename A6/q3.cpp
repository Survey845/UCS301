#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int value){
        val = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DLL{
    Node* tail;
    int count;
public:
    DLL(){
        tail = nullptr;
        count = 0;
    }
    void insertBegin(int value){
        Node* newNode = new Node(value);
        if(tail==nullptr){
            tail=newNode;
            tail->next = newNode;
        } else{
            newNode->next=tail->next;
            tail->next=newNode;
        }
        count = count+1;
    }
    void counter(){
        cout<<count<<endl;
    }
};

class CLL{
    Node* head;
    int count;
public:
    CLL(){
        head=nullptr;
        count=0;
    }

    void insertBegin(int value){
        Node* newNode = new Node(value);
        if(head==nullptr){
            head = newNode;
            newNode->next=newNode;
        } else{
            newNode->next=head;
            head=newNode;
        }
        count++;
    }
    void counter(){
        cout<<count<<endl;
    }
};

int main(){
    // DLL dll;
    // dll.insertBegin(3);
    // dll.insertBegin(2);
    // dll.insertBegin(1);
    // dll.counter();
    CLL cll;
    cll.insertBegin(1);
    cll.insertBegin(2);
    cll.counter();
}
