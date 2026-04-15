#include <iostream>
using namespace std;

// Structure for a Tree Node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int value) {
        data = value;
        left = right = NULL;
    }
};

// Class for Binary Search Tree
class BinarySearchTree {
private:
    TreeNode* root;

    // Helper function to insert a node
    TreeNode* insertNode(TreeNode* node, int key) {
        if (node == NULL) {
            return new TreeNode(key);
        }

        if (key < node->data) {
            node->left = insertNode(node->left, key);
        } else {
            node->right = insertNode(node->right, key);
        }

        return node;
    }

    // In-order traversal (Left, Root, Right)
    void inOrder(TreeNode* node) {
        if (node != NULL) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

    // Post-order traversal (Left, Right, Root)
    void postOrder(TreeNode* node) {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->data << " ";
        }
    }

public:
    // Constructor
    BinarySearchTree() {
        root = NULL;
    }

    // Insert function
    void insert(int key) {
        root = insertNode(root, key);
    }

    // In-order traversal
    void In_order_traversal() {
        inOrder(root);
        cout << endl;
    }

    // Post-order traversal
    void post_order_traversal() {
        postOrder(root);
        cout << endl;
    }
};

// Main function to test
int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "In-order Traversal: ";
    bst.In_order_traversal();

    cout << "Post-order Traversal: ";
    bst.post_order_traversal();

    return 0;
}