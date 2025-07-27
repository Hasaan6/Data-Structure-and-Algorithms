#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
};

class tree {
public:
    node* root;

    node* createnode(int data) {
        node* newnode = new node();
        newnode->data = data;
        newnode->left = newnode->right = NULL;
        return newnode;
    }

    node* insert(node* root, int data) {
        if (root == NULL) {
            root = createnode(data);
        }
        else if (data < root->data) {
            root->left = insert(root->left, data);
        }
        else {
            root->right = insert(root->right, data);
        }
        return root;
    }

    // Print parent and sibling nodes
    void printSiblingsWithParents(node* root) {
        if (root == NULL) return;

        // If both children exist, they are siblings
        if (root->left != NULL && root->right != NULL) {
            cout << "Parent: " << root->data 
                 << " -> Left Child: " << root->left->data 
                 << ", Right Child: " << root->right->data << endl;
        }

        printSiblingsWithParents(root->left);
        printSiblingsWithParents(root->right);
    }
};

int main() {
    node* root = NULL;
    tree t;
    root = t.insert(root, 15);
    t.insert(root, 10);
    t.insert(root, 50);
    t.insert(root, 51);

    cout << "Siblings and their parents:\n";
    t.printSiblingsWithParents(root);
    
    return 0;
}

