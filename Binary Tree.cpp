#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertBST(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insertBST(root->left, val);
    } else {

        root->right = insertBST(root->right, val);
    }
    return root;
}

int main() {

    Node* root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 3);
    insertBST(root, 7);
    insertBST(root, 1);
    insertBST(root, 4);


    cout << "Root: " << root->data << endl;
    if (root->left) {
        cout << "Left child: " << root->left->data << endl;
    }
    if (root->right) {
        cout << "Right child: " << root->right->data << endl;
    }

    return 0;
}

