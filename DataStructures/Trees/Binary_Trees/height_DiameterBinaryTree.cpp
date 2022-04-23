
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

// Time comlexity: O(N)

int calcHeight(Node* root){
    if(root == NULL) return 0;
    int lheight = calcHeight(root->left);
    int rheight = calcHeight(root->right);
    return max(lheight, rheight)+1;
}

// longest path b/w any two leaves of a binary tree
//  Time complexity: O(N^2)
int calcDiameter(Node* root){
    if(root == NULL) return 0;
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);
    int currDiameter = lHeight + rHeight + 1;
    
    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);

    return max(currDiameter, max(lDiameter, rDiameter));
}

int calcDiameterOptimised(Node* root, int* height){
    if(root == NULL){
        *height = 0;return 0;
    }
    int lHeight = 0, rHeight = 0;
    int lDiameter = calcDiameterOptimised(root->left, &lHeight);
    int rDiameter = calcDiameterOptimised(root->right, &rHeight);

    int currDiameter = lHeight+rHeight +1;
    *height = max(lHeight, rHeight) + 1;

    return max(currDiameter, max(lDiameter, rDiameter));
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

    cout<<"The height of the tree is: "<<calcHeight(root)<<endl;
    cout<<"The diameter of the tree is: "<<calcDiameter(root)<<endl;
    int height = 0;
    cout<<"The optimised diameter of the tree is: "<<calcDiameterOptimised(root, &height)<<endl;
    return 0;
}