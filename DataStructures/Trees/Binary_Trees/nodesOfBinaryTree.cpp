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

int noOfNodes(Node* root){
    if(root == NULL) return 0;
    return noOfNodes(root->left) + noOfNodes(root->right) +1;
}

int sumOfNodes(Node* root){
    int sum = 0;
    if(root == NULL) return 0;
    return sumOfNodes(root->left) + sumOfNodes(root->right) + root->data;
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

    cout<<"No of nodes in the tree is: "<<noOfNodes(root)<<endl;
    cout<<"Sum of nodes in the tree is: "<<sumOfNodes(root)<<endl;
    return 0;
}