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

    void deleteDuplicates(int val){
        while(head!=NULL && head->val==val){
            head = head->next;
        }
        if(head==NULL){
            cout<<"Linked List is empty..."<<endl;
        }
        Node* temp = head;
        while(temp->next!=NULL){
            if(temp->next->val==val){
                temp->next = temp->next->next;
            } else{
                temp = temp->next;
            }
        }
    }
};

int main(){
    LL linkedlist;
    linkedlist.insertHead(3);
    linkedlist.insertHead(2);
    linkedlist.insertHead(1);
    linkedlist.insertHead(1);
    linkedlist.print();
    linkedlist.deleteDuplicates(1);
    linkedlist.print();
    return 0;
}