#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int data)
{
    struct Node* ptr1
    = (struct Node*)malloc(
        sizeof(struct Node));

    struct Node* temp = *head_ref;
    ptr1->data = data;
    ptr1->next = *head_ref;

    if (*head_ref != NULL) {

        while (temp->next != *head_ref)
            temp = temp->next;

        temp->next = ptr1;
    }
    else

        ptr1->next = ptr1;

    *head_ref = ptr1;
}

void deleteNode(
    Node*& head_ref, Node* del)
{
    if (head_ref == del)
        head_ref = del->next;

    struct Node* temp = head_ref;

    while (temp->next != del) {
        temp = temp->next;
    }

    temp->next = del->next;

    free(del);

    return;
}

bool isEvenParity(int x)
{
    int parity = 0;
    while (x != 0) {
        if (x & 1)
            parity++;
        x = x >> 1;
    }

    if (parity % 2 == 0)
        return true;
    else
        return false;
}

void deleteEvenParityNodes(Node*& head)
{
    if (head == NULL)
        return;

    if (head == head->next) {
        if (isEvenParity(head->data))
            head = NULL;
        return;
    }

    struct Node* ptr = head;

    struct Node* next;

    do {
        next = ptr->next;

        if (isEvenParity(ptr->data))
            deleteNode(head, ptr);

        ptr = next;

    } while (ptr != head);

    if (head == head->next) {
        if (isEvenParity(head->data))
            head = NULL;
        return;
    }
}

void printList(struct Node* head)
{
    if (head == NULL) {
        cout << "Empty List\n";
        return;
    }

    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
}

int main()
{
    struct Node* head = NULL;

    push(&head, 21);
    push(&head, 13);
    push(&head, 6);
    push(&head, 34);
    push(&head, 9);
    push(&head, 11);

    deleteEvenParityNodes(head);

    printList(head);
    cout<<endl;
    return 0;
}
