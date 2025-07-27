//write a cpp program that prints only the leaf nodes in a tree

#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node* left;
	node* right;
};

class tree{
	public:
	node* root;
	
	
	node* createnode(int data){
		node* newnode=new node();
		newnode->data=data;
		newnode->left=newnode->right=NULL;
		return newnode;
	}
	
	node* insert(node* root,int data){
		if(root==NULL){
			root=createnode(data);
		}
		else if(data<root->data){
			root->left=insert(root->left,data);
		}
		else
		{
			root->right=insert(root->right,data);
		}
		return root;
	}
	
	void preorder(node* root){
		if(root==NULL){
			return ;
	    }
	    
	    if (root->left == NULL && root->right == NULL) {
            cout << root->data << " ";
            return;
        }
			preorder(root->left);
			preorder(root->right);
	}
};

int main(){
	node* root=NULL;
	tree t;
	root=t.insert(root,15);
	t.insert(root,10);
    t.insert(root,50);
    t.insert(root,51);
    t.preorder(root);
}
