#include <iostream>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node * prev;

    Node(int num){
        val = num;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList{
public:
    Node* head;

    LinkedList(){
        head = nullptr;
    }

    bool search(int value){
        Node* current = head;
        while(current){
            if(current->val==value){
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void insertBegin(int value){
        Node* newNode = new Node(value);
        if(!head){
            head = newNode;
        } else{
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void insertEnd(int value){
        Node* newNode = new Node(value);
        if(!head){
            head = newNode;
        } else{
            Node* temp = head;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void insertAfter(int value, int num){
        Node* newNode = new Node(value);
        Node* temp = head;
        while(temp){
            if(temp->val==num){
                newNode->next = temp->next;
                newNode->prev = temp;
                if(temp->next){
                    temp->next->prev = newNode;
                }
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
        cout<<"Value not found in list..."<<endl;
    }

    void delBegin(){
        if(!head){
            cout<<"No node to delete..."<<endl;
            return;
        } else{
            Node* temp = head;
            head = head->next;
            if(head){
                head->prev = nullptr;
            }
        }
    }

    void delEnd(){
        if(!head){
            cout<<"No node to delete..."<<endl;
            return;
        } else{
            Node* temp = head;
            while(temp->next){
                temp = temp->next;
            }
            if(temp->prev){
                temp->prev->next=nullptr;
            } else{
                head = nullptr;
            }
        }
    }

    void delAfter(int num){
        Node* cur = head;
        while(cur){
            if(cur->val==num){
                Node* temp = cur->next;
                if(temp){
                    cur->next=temp->next;
                    if(temp->next){
                        temp->next->prev=cur;
                    }
                    delete temp;
                } else{
                    cout<<"No elements to delete after..."<<endl;
                }
                return;
            }
            cur = cur->next;
        }
        cout<<"Value "<<num<<"not found in list."<<endl;
    }
};

int main(){
    LinkedList ll;

    ll.insertBegin(5);
    ll.insertEnd(4);
    ll.insertAfter(3,4);
    ll.insertAfter(2,3);
    ll.insertEnd(1);

    if(ll.search(1)){
        cout<<"True"<<endl;
    }

    ll.delBegin();

    if(ll.search(5) || ll.search(1)){
        cout<<"Deletion at beginning or end was unsuccessful..."<<endl;
    }

    ll.delAfter(4);

    if(ll.search(1)){
        cout<<"Deletion after value was unsuccessful..."<<endl;
    }

    return 0;
}
