#include <bits/stdc++.h> 
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void flatten(Node* root){
    if(root == NULL or (root->left == NULL or root->right == NULL)) return;
    
    if(root-> left != NULL){
        flatten(root-> left);

        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node* t = root->right;
        while(t->right != NULL){
            t= t->right;
        }
        t->right = temp;
    }
    flatten(root->right);
}

// Time complexity: O(N)
//  traverse from Right, Left, and Root.
Node* previous = NULL;
void flattenBetter(Node* root){
    if(root == NULL) return;
    flattenBetter(root->right);
    flattenBetter(root->left);
    root->right = previous;
    root->left = NULL;
    previous = root;
}


void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    inOrder(root);
    cout<<endl;
    flattenBetter(root);
    inOrder(root);
    cout<<endl;
    return 0;
}