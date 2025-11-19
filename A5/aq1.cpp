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

ListNode* findIntersectionNode (ListNode *A, ListNode *B, int difference) {
    while(difference > 0) {
        A = A->next;
        difference--;
    }
    while (A != NULL && B!= NULL) {
        if (A==B) {
            return A;
        }
        A = A->next;
        B = B->next;
    }
    return NULL;
}
ListNode* getIntersectionNode(ListNode *A, ListNode *B) {
    int firstLength = 0;
    ListNode* firstCurrNode = A;
    while (firstCurrNode != NULL) {
        firstLength++;
        firstCurrNode = firstCurrNode->next;
    }
    int secondLength = 0;
    ListNode* secondCurrNode = B;
    while (secondCurrNode != NULL) {
        secondLength++;
        secondCurrNode = secondCurrNode->next;
    }
    if (firstLength < secondLength) {
        return findIntersectionNode (B, A, secondLength - firstLength);
    } else {
        return findIntersectionNode (A, B, firstLength - secondLength);
    }
}

int main() {
    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);

    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = common;

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = common;

    ListNode* intersection = getIntersectionNode(headA, headB);

    if (intersection != NULL) {
        cout << "Intersection node data: " << intersection->data << endl;
    } else {
        cout << "No intersection node found." << endl;
    }

    ListNode* headC = new ListNode(1);
    headC->next = new ListNode(2);
    ListNode* headD = new ListNode(3);
    headD->next = new ListNode(4);

    ListNode* noIntersection = getIntersectionNode(headC, headD);

    if (noIntersection != NULL) {
        cout << "Intersection node data: " << noIntersection->data << endl;
    } else {
        cout << "No intersection node found." << endl;
    }

    return 0;
}
