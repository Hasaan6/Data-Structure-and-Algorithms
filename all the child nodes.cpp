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

    // Print all child nodes (i.e., all nodes except the root)
    void printChildNodes(node* root) {
        if (root == NULL) return;

        if (root->left != NULL) {
            cout << root->left->data << " ";
            printChildNodes(root->left);
        }
        if (root->right != NULL) {
            cout << root->right->data << " ";
            printChildNodes(root->right);
        }
    }
};

int main() {
    node* root = NULL;
    tree t;
    root = t.insert(root, 15);
    t.insert(root, 10);
    t.insert(root, 50);
    t.insert(root, 51);

    cout << "Child nodes: ";
    t.printChildNodes(root);
    cout << endl;

    return 0;
}

