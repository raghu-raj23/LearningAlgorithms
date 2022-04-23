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

int height(Node* node){
    if(node == NULL){
        return 0;
    }
    int lh =height(node->left);
    int rh =height(node->right);
    return max(lh,rh)+1;
}

// Time complexity: O(N^2)
bool isBalanced(Node* root){
    if(root == NULL){
        return true;
    }
    if(isBalanced(root->left) == false){
        return false;
    }
    if(isBalanced(root->right) == false){
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh - rh) <= 1){
        return true;
    }
    return false;
}

// Time complexity O(N)
bool isBalancedOptimised(Node* root, int *height){
    int lh=0,rh = 0;
    if(root == NULL){
        return true;
    }
    if(!isBalancedOptimised(root->left, &lh)){
        return false;
    }
    if(!isBalancedOptimised(root->right, &rh)){
        return false;
    }
    *height = max(lh, rh) + 1;
    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
    }
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

    if(isBalanced(root)){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Unbalanced"<<endl;
    }
    int height =0;
    if(isBalancedOptimised(root, &height)){
        cout<<"Optimised Balanced"<<endl;
    }
    else{
        cout<<"Optimised Unbalanced"<<endl;
    }

    return 0;
}