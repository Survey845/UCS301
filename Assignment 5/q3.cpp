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
        } while(temp->next!=NULL);
        cout<<endl;
    }

    void middle(){
        int length;
        if(head!=NULL){
            length = 0;
        } else{
            cout<<"Linked List is empty..."<<endl;
            return;
        }
        Node* temp1 = head;
        while(temp1->next!=NULL){
            length++;
            temp1 = temp1->next;
        }
        int counter = 0;
        Node* temp2 = head;
        while(counter<(length/2)){
            counter++;
            temp2 = temp2->next;
        }
        cout<<"The middle element of the linked list is: "<<temp2->val<<endl;
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
    linkedlist.middle();
    return 0;
}