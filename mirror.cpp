#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    node(int d) {
        data = d;
        left = right = NULL;
    }
};

class tree {
public:
    node* insert(node* root, int data) {
        if (root == NULL) {
            return new node(data);
        }
        if (data < root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
        return root;
    }

    void inorder(node* root) {
        if (root == NULL) {
            return;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(node* root) {
        if (root == NULL) {
            return;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(node* root) {
        if (root == NULL) {
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    void mirror(node* root) {
        if (root == NULL) {
            return;
        }

        // Swap left and right
        node* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Recursively mirror the subtrees
        mirror(root->left);
        mirror(root->right);
    }
};

int main() {
    node* r = NULL;
    tree t;
    int n, d;

    cout << "How many values? ";
    cin >> n;
    cout << "Enter values: " << endl;

    for (int i = 0; i < n; ++i) {
        cin >> d;
        r = t.insert(r, d);
    }

    cout << "\nBefore Mirroring:";
    cout << "\nInorder: ";
    t.inorder(r);
    cout << "\nPreorder: ";
    t.preorder(r);
    cout << "\nPostorder: ";
    t.postorder(r);

    t.mirror(r); // Mirror the tree

    cout << "\n\nAfter Mirroring:";
    cout << "\nInorder: ";
    t.inorder(r);
    cout << "\nPreorder: ";
    t.preorder(r);
    cout << "\nPostorder: ";
    t.postorder(r);

    cout << endl;
    return 0;
}

