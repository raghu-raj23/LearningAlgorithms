#include <bits/stdc++.h> 
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;
    Node(int val){
        this->data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    Node* root = NULL;
    root = insert(root, 5);
    insert(root, 2);
    insert(root, 3);
    insert(root, 9);
    insert(root, 1);
    insert(root, 8);
    insert(root, 7);

    inorder(root);
    return 0;
}