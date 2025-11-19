#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool isBSTUtil(Node* root, Node*& prev) {
    if (root == NULL) {
        return true;
    }

    if (!isBSTUtil(root->left, prev)) {
        return false;
    }

    if (prev != NULL && root->data <= prev->data) {
        return false;
    }

    prev = root;

    return isBSTUtil(root->right, prev);
}

bool isBST(Node* root) {
    Node* prev = NULL;
    return isBSTUtil(root, prev);
}

int main() {
    Node* root1 = new Node(4);
    root1->left = new Node(2);
    root1->right = new Node(6);
    root1->left->left = new Node(1);
    root1->left->right = new Node(3);
    root1->right->left = new Node(5);
    root1->right->right = new Node(7);

    if (isBST(root1)) {
        cout << "Tree 1 is a BST." << endl;
    } else {
        cout << "Tree 1 is NOT a BST." << endl;
    }

    Node* root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);
    root2->left->left = new Node(1);
    root2->left->right = new Node(5);

    if (isBST(root2)) {
        cout << "Tree 2 is a BST." << endl;
    } else {
        cout << "Tree 2 is NOT a BST." << endl;
    }

    return 0;
}
