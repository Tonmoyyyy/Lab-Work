#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;


    Node(int value) {  // Constructor to initialize the Node with data
        data = value;
        left = NULL;
        right = NULL;
    }
};


void inOrderTraversal(Node* root) { // In-order traversal: Left -> Root -> Right
    if (root == NULL) return;

    // Traverse left subtree
    inOrderTraversal(root->left);

    // Visit the root node
    cout << root->data << " ";

    // Traverse right subtree
    inOrderTraversal(root->right);
}

// Pre-order traversal: Root -> Left -> Right
void preOrderTraversal(Node* root) {
    if (root == NULL) return;

    // Visit the root node
    cout << root->data << " ";

    // Traverse left subtree
    preOrderTraversal(root->left);

    // Traverse right subtree
    preOrderTraversal(root->right);
}

// Post-order traversal: Left -> Right -> Root
void postOrderTraversal(Node* root) {
    if (root == NULL) return;

    // Traverse left subtree
    postOrderTraversal(root->left);

    // Traverse right subtree
    postOrderTraversal(root->right);

    // Visit the root node
    cout << root->data << " ";
}

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Pre-order traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
