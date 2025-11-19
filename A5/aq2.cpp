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

ListNode* reverseLinkedListKGroup(ListNode* head, int k) {
    ListNode* currentNode = head;
    int totalNodes = 0;
    while (currentNode != NULL && totalNodes < k) {
        currentNode = currentNode->next;
        totalNodes++;
    }
    if (totalNodes < k) {
        return head;
    }
    currentNode = head;
    ListNode* prevNode = NULL;
    ListNode* nextNode;
    int nodeCount = 0;
    while (nodeCount < k) {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
        nodeCount++;
    }
    head->next = reverseLinkedListKGroup(nextNode, k);
    return prevNode;
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
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);

    int k = 3;

    cout << "Original list: " << endl;
    printList(head);

    ListNode* reversedHead = reverseLinkedListKGroup(head, k);

    cout << "List after reversing in groups of " << k << ": " << endl;
    printList(reversedHead);

    return 0;
}
