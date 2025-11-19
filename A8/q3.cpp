#include <iostream>
#include <algorithm>
#include <queue>

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

Node* insert(Node* root, int key) {
    if (root == NULL) {
        return new Node(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    return root;
}

Node* findMin(Node* root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int maxDepth(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + max(leftDepth, rightDepth);
}

int minDepth(Node* root) {
    if (root == NULL) {
        return 0;
    }

    queue<pair<Node*, int>> q;
    q.push({root, 1});

    while (!q.empty()) {
        pair<Node*, int> current = q.front();
        q.pop();

        Node* node = current.first;
        int depth = current.second;

        if (node->left == NULL && node->right == NULL) {
            return depth;
        }

        if (node->left != NULL) {
            q.push({node->left, depth + 1});
        }
        if (node->right != NULL) {
            q.push({node->right, depth + 1});
        }
    }
    return 0;
}

void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Original tree (In-order): ";
    inOrder(root);
    cout << endl;

    cout << "--- Depths ---" << endl;
    cout << "Max depth (height): " << maxDepth(root) << endl;
    cout << "Min depth: " << minDepth(root) << endl;

    cout << "\n--- Deleting 20 (0 children) ---" << endl;
    root = deleteNode(root, 20);
    cout << "Tree: ";
    inOrder(root);
    cout << endl;

    cout << "\n--- Deleting 30 (1 child) ---" << endl;
    root = deleteNode(root, 30);
    cout << "Tree: ";
    inOrder(root);
    cout << endl;

    cout << "\n--- Deleting 50 (2 children) ---" << endl;
    root = deleteNode(root, 50);
    cout << "Tree: ";
    inOrder(root);
    cout << endl;

    cout << "\n--- Depths After Deletion ---" << endl;
    cout << "Max depth (height): " << maxDepth(root) << endl;
    cout << "Min depth: " << minDepth(root) << endl;

    return 0;
}
