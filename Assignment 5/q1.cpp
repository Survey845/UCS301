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

        if(head==NULL){
            head = node;
            return;
        }
        node->next = this->head;
        this->head = node;
    }

    void insertEnd(int val){
        Node* node  = new Node(val);
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = node;
    }

    void insertBefore(int val, int pos){
        int counter = 1;
        Node* node = new Node(val);
        Node* temp = head;
        while(counter<pos){
            temp = temp->next;
            counter++;
        }
        node->next = temp->next;
        temp->next = node;
    }

    void insertAfter(int val, int pos){
        int counter = 1;
        Node* node = new Node(val);
        Node* temp = head;
        while(counter!=pos){
            temp = temp->next;
            counter++;
        }
        node->next = temp->next;
        temp->next = node;
    }

    void deleteHead(){
        head = head->next;
    }

    void deleteEnd(){
        Node* temp = head;
        if(head->next==NULL){
            cout<<"Linked List is empty..."<<endl;
            return;
        }
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        temp->next = NULL;
    }

    void deleteNode(int pos){
        int counter = 1;
        Node* temp = head;
        while(counter!=(pos-1)){
            temp = temp->next;
            counter++;
        }
        temp->next = temp->next->next;
    }

    void search(int val){
        Node* temp = head;
        int counter = 0;
        while(temp->val!=val){
            temp = temp->next;
            counter++;
        }
        if(counter!=0){
            cout<<"Value found at node: "<<counter+1<<endl;
        } else{
            cout<<"Value not found..."<<endl;
        }

    }

    void print(){
        Node* temp = head;
        if(head==NULL){
            cout<<"List is empty..."<<endl;
            return;
        }
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

};

int main(){
    LL linkedlist;
    linkedlist.insertHead(5);
    linkedlist.insertHead(4);
    linkedlist.insertHead(3);
    linkedlist.insertHead(2);
    linkedlist.insertHead(1);
    linkedlist.insertEnd(6);
    linkedlist.insertAfter(7,6);
    linkedlist.insertAfter(34,3);
    linkedlist.deleteHead();
    linkedlist.deleteEnd();
    linkedlist.deleteNode(3);
    linkedlist.print();
    linkedlist.search(5);
    return 0;

}