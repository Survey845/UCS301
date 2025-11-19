#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int value){
        val = value;
        next = nullptr;
    }
};

class CircularLinkedList{
    Node* tail;
public:
    CircularLinkedList(){
        tail = nullptr;
    }

    void insertBegin(int value){
        Node* newNode = new Node(value);

        if(tail==nullptr){
            tail = newNode;
            tail->next = newNode;
        }
        /*else if(!tail->next && tail){
            tail->next = newNode;
            tail = newNode;
        } */else{
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }

    void display(){
        Node* cur = tail;
        int count = 0;
        while(count<2){
            if(cur==tail){
                count++;
            }
            cout<<cur->val<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }
};

int main(){
    CircularLinkedList cll;

    cll.insertBegin(20);
    cll.insertBegin(100);
    cll.insertBegin(40);
    cll.insertBegin(80);
    cll.insertBegin(60);

    cll.display();
}
