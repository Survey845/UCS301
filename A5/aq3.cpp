#include <iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void removeLoop(ListNode* list) {
    if (list == NULL || list->next == NULL) {
        return;
    }
    ListNode *slowPtr = list->next, *fastPtr = list->next->next;
    ListNode *prevNode = list->next;
    while (fastPtr != NULL && fastPtr->next != NULL) {
        if(slowPtr == fastPtr) {
            slowPtr = list;
            break;
        }
        slowPtr = slowPtr->next;
        prevNode = fastPtr->next;
        fastPtr = fastPtr->next->next;
    }
    if (fastPtr == NULL || fastPtr->next == NULL) {
        return;
    }
    while (slowPtr != fastPtr) {
        prevNode = fastPtr;
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
    }
    prevNode->next = NULL;
    return;
}

void printList(ListNode* node) {
    while (node != NULL) {
        cout << node->data << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    node5->next = node3;

    removeLoop(head);

    cout << "List after removing loop: " << endl;
    printList(head);

    return 0;
}
