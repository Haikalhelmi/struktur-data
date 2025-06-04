// Program Tree Lengkap
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class Tree {
public:
    Node* root;

    Tree() {
        root = NULL;
    }

    // Fungsi untuk menambahkan node
    Node* insert(Node* node, int value) {
        if (node == NULL) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }

        return node;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    // Fungsi inorder traversal
    void inorder(Node* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void printInOrder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    Tree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);

    // Cetak hasil inorder traversal
    tree.printInOrder(); // Output: 5 10 15

    return 0;
}

