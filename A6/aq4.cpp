#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node *prev;

    Node():prev(NULL),next(NULL){}
    Node(int data):data(data),prev(NULL),next(NULL){}

};
class doublell
{
public:
    Node *head;
    void appendNode(Node *n)
    {
        Node *temp=head;
        if(temp==NULL)
        {
            head=n;

        }
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=n;
            n->prev=temp;
        }
    }

    void print()
    {
        Node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }

    void printReverse()
    {
        Node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        while(temp!=NULL)
        {
            cout<<temp->data<<" ->";
            temp=temp->prev;
        }
        cout<<endl;
    }

    void correctPointer()
    {
        if(!head)
        {
            return;
        }
        Node *temp=head;
        while(temp->next!=NULL)
        {
            if(temp->next->prev!=temp)
            {
                temp->next->prev=temp;
            }
            temp=temp->next;
        }
    }
};

int main()
{
    doublell ll;
    ll.head = new Node(1);
    ll.head->next = new Node(2);
    ll.head->next->prev = ll.head;
    ll.head->next->next = new Node(3);
    ll.head->next->next->prev =ll.head;
    ll.head->next->next->next = new Node(4);
    ll.head->next->next->next->prev = ll.head->next->next;

    cout << "\nIncorrect Linked List: ";
    ll.print();
    ll.printReverse();

    ll.correctPointer();

    cout << "\nCorrected Linked List: ";
    ll.print();
    ll.printReverse();


    return 0;
}
