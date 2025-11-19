#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

Node* insert(Node*& root, int key) {
    Node* newNode = new Node(key);
    if (root == NULL) {
        root = newNode;
        return newNode;
    }

    Node* current = root;
    Node* parentNode = NULL;

    while (current != NULL) {
        parentNode = current;
        if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    newNode->parent = parentNode;
    if (key < parentNode->data) {
        parentNode->left = newNode;
    } else {
        parentNode->right = newNode;
    }
    return newNode;
}

Node* searchRecursive(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return searchRecursive(root->left, key);
    }
    return searchRecursive(root->right, key);
}

Node* searchIterative(Node* root, int key) {
    Node* current = root;
    while (current != NULL && current->data != key) {
        if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return current;
}

Node* findMin(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* findMax(Node* root) {
    if (root == NULL) {
        return NULL;
    }
    Node* current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    return current;
}

Node* inOrderSuccessor(Node* n) {
    if (n == NULL) {
        return NULL;
    }
    if (n->right != NULL) {
        return findMin(n->right);
    }
    Node* p = n->parent;
    while (p != NULL && n == p->right) {
        n = p;
        p = p->parent;
    }
    return p;
}

Node* inOrderPredecessor(Node* n) {
    if (n == NULL) {
        return NULL;
    }
    if (n->left != NULL) {
        return findMax(n->left);
    }
    Node* p = n->parent;
    while (p != NULL && n == p->left) {
        n = p;
        p = p->parent;
    }
    return p;
}

int main() {
    Node* root = NULL;
    Node* node50 = insert(root, 50);
    insert(root, 30);
    Node* node70 = insert(root, 70);
    Node* node20 = insert(root, 20);
    Node* node40 = insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "--- Search ---" << endl;
    Node* res1 = searchRecursive(root, 40);
    cout << "Recursive search for 40: " << (res1 ? "Found" : "Not Found") << endl;
    Node* res2 = searchIterative(root, 90);
    cout << "Iterative search for 90: " << (res2 ? "Found" : "Not Found") << endl;

    cout << "\n--- Min/Max ---" << endl;
    Node* minNode = findMin(root);
    cout << "Min element: " << (minNode ? minNode->data : -1) << endl;
    Node* maxNode = findMax(root);
    cout << "Max element: " << (maxNode ? maxNode->data : -1) << endl;

    cout << "\n--- Successor ---" << endl;
    Node* succ1 = inOrderSuccessor(node20);
    cout << "Successor of 20: " << (succ1 ? succ1->data : -1) << endl;
    Node* succ2 = inOrderSuccessor(node40);
    cout << "Successor of 40: " << (succ2 ? succ2->data : -1) << endl;
    Node* succ3 = inOrderSuccessor(maxNode);
    cout << "Successor of 80 (max): " << (succ3 ? "None" : "None") << endl;

    cout << "\n--- Predecessor ---" << endl;
    Node* pred1 = inOrderPredecessor(node70);
    cout << "Predecessor of 70: " << (pred1 ? pred1->data : -1) << endl;
    Node* pred2 = inOrderPredecessor(node40);
    cout << "Predecessor of 40: " << (pred2 ? pred2->data : -1) << endl;
    Node* pred3 = inOrderPredecessor(minNode);
    cout << "Predecessor of 20 (min): " << (pred3 ? "None" : "None") << endl;

    return 0;
}
