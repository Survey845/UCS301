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

class CLL{
    Node* tail;
public:
    CLL(){
        tail = nullptr;
    }

    void insertEnd(int value){
        Node* newNode = new Node(value);
        if(tail==nullptr){
            tail=newNode;
            newNode->next=newNode;
        } else{
            newNode->next=tail->next;
            tail->next=newNode;
            tail=newNode;
        }
    }

    void split(CLL &cll2){
        if (tail == nullptr) {
            return;
        }
        if (tail->next == tail) {
            return;
        }

        Node* slow = tail->next;
        Node* fast = tail->next;

        while(fast != tail && fast->next != tail){
            fast = fast->next->next;
            slow = slow->next;
        }

        Node* head1 = tail->next;
        Node* head2 = slow->next;

        cll2.tail = this->tail;
        cll2.tail->next = head2;

        this->tail = slow;
        this->tail->next = head1;
    }

    void display(){
        if(tail == nullptr) {
            cout << "Empty" << endl;
            return;
        }
        Node* cur = tail->next;
        do{
            cout<<cur->val<<" ";
            cur=cur->next;
        } while(cur!=tail->next);
        cout<<endl;
    }
};

int main(){
    CLL cll1, cll2;
    cll1.insertEnd(4);
    cll1.insertEnd(7);
    cll1.insertEnd(9);

    cout << "Original List: ";
    cll1.display();

    cll1.split(cll2);

    cout << "First List: ";
    cll1.display();

    cout << "Second List: ";
    cll2.display();

    CLL cll3, cll4;
    cll3.insertEnd(1);
    cll3.insertEnd(2);
    cll3.insertEnd(3);
    cll3.insertEnd(4);

    cout << "Original List: ";
    cll3.display();

    cll3.split(cll4);

    cout << "First List: ";
    cll3.display();

    cout << "Second List: ";
    cll4.display();

    return 0;
}
