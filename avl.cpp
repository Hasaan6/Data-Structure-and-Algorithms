#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    int height;
};

class AVL {
public:
    node* root;

    AVL() {
        root = NULL;
    }

    // Create a new node
    node* createNode(int data) {
        node* newnode = new node();
        newnode->data = data;
        newnode->left = newnode->right = NULL;
        newnode->height = 1; // New node is initially added at leaf
        return newnode;
    }

    // Get height of node
    int height(node* n) {
       if (n != nullptr)
    return n->height;
    else
    return 0;
    }

    // Get balance factor
    int getBalance(node* n) {
        if (n != nullptr) {
    return height(n->left) - height(n->right);
} else {
    return 0;
}
    }

    // Right rotate
    node* rightRotate(node* y) {
        node* x = y->left;
        node* T2 = x->right;

        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    // Left rotate
    node* leftRotate(node* x) {
        node* y = x->right;
        node* T2 = y->left;

        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    // Insert a node and balance the tree
    node* insert(node* root, int data) {
        if (root == NULL) {
            return createNode(data);
        }

        if (data < root->data)
            root->left = insert(root->left, data);
        else if (data > root->data)
            root->right = insert(root->right, data);
        else // Duplicate keys not allowed
            return root;

        // Update height of this ancestor node
        root->height = 1 + max(height(root->left), height(root->right));

        // Get balance factor
        int balance = getBalance(root);

        // If unbalanced, then 4 cases

        // Left Left Case
        if (balance > 1 && data < root->left->data)
            return rightRotate(root);

        // Right Right Case
        if (balance < -1 && data > root->right->data)
            return leftRotate(root);

        // Left Right Case
        if (balance > 1 && data > root->left->data) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Left Case
        if (balance < -1 && data < root->right->data) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // Print only leaf nodes (as in original preorder)
    void printLeaves(node* root) {
        if (!root) return;

        if (!root->left && !root->right) {
            cout << root->data << " ";
            return;
        }

        printLeaves(root->left);
        printLeaves(root->right);
    }
};

int main() {
    AVL t;
    t.root = t.insert(t.root, 15);
    t.root = t.insert(t.root, 10);
    t.root = t.insert(t.root, 50);
    t.root = t.insert(t.root, 51);

    t.printLeaves(t.root);  // Prints only leaf nodes
}

