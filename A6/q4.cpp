#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int value){
        val = value;
    }
};

class DLL{
    Node* tail;
public:
    DLL(){
        tail = nullptr;
    }

    void insertEnd(int value){
        Node* newNode = new Node(value);
    if(tail==nullptr){
        tail==newNode;
        newNode->next=newNode;
        newNode->prev=newNode;
    } else{
        newNode->next=tail->next;
        newNode->prev=tail;
        tail=newNode;
    }
    }

    bool isPalindrome(){
        if(tail==nullptr || tail->next==tail){
            return true;
        }
        Node* l = tail->next;
        Node* r = tail;
        while(l!=r && l->prev!=r){
            if(l->val!=r->val){
                return false;
            }
            l=l->next;
            r=r->prev;
        }
        return true;
    }
};

int main(){
    DLL dll;
    dll.insertEnd('a');
    dll.insertEnd('b');
    dll.insertEnd('a');
    if(dll.isPalindrome()){
        cout<<"True"<<endl;
    } else{
        cout<<"False"<<endl;
    }

}
