#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;

    Node(){
        val = 0;
        next = NULL;
    }

    Node(int val){
        this->val = val;
        next = NULL;
    }
};

class LL{
    Node* head;
public:

    LL(){
        head = NULL;
    }
    void insertHead(int val){
        Node* node = new Node(val);
        node->next = head;
        this->head = node;
    }

    void print(){
        Node* temp = head;
        if(head->next==NULL){
            cout<<"Linked List is empty..."<<endl;
            return;
        }
        do {
            cout<<temp->val<<" ";
            temp = temp->next;
        } while(temp!=NULL);
        cout<<endl;
    }

    void reverse(){
        Node* cur = head;
        Node* prev = NULL;
        Node* next;
        while(cur!=NULL){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }
};

int main(){
    LL linkedlist;
    linkedlist.insertHead(5);
    linkedlist.insertHead(4);
    linkedlist.insertHead(3);
    linkedlist.insertHead(2);
    linkedlist.insertHead(1);
    linkedlist.print();
    linkedlist.reverse();
    linkedlist.print();
    return 0;
}