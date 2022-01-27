#include <bits/stdc++.h> 
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

bool check_BST(Node *root, Node* min = NULL, Node* max=NULL){
    if(root == NULL)
        return true;
    if(min != NULL && root->data <= min->data){
        return false;
    }
    if(max != NULL && root->data >= max->data){
        return false;
    }
    bool leftSubTree = check_BST(root->left, min, root);
    bool rightSubTree = check_BST(root->right, root, max);
    return leftSubTree && rightSubTree;
}
int main()
{
    Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(8);
    // root->left->left = new Node(4);
    check_BST(root, NULL, NULL)?cout<<"Valid BST"<<endl:cout<<"Invalid BST"<<endl;
    return 0;
}
// O(n) time complexity as we are traversing each element only once.
