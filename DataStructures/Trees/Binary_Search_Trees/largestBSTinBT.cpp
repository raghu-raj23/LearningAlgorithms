#include <bits/stdc++.h> 
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

struct Info{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};


Info finder(Node* root){
    if(root == NULL) return {0, INT_MIN, INT_MAX, 0, true};

    if(root->left == NULL && root->right == NULL) return {1, root->data, root->data, 1, true};

    Info left = finder(root->left);
    Info right = finder(root->right);

    Info curr;
    curr.size = left.size + right.size + 1;

    if(left.isBST && right.isBST && left.max < root->data && right.min > root->data){
        curr.min = min(root->data, min(left.min, right.min));
        curr.max = max(root->data, max(left.max, right.max));
        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }
    curr.ans = max(left.ans, right.ans);
    curr.isBST = false;
    return curr;
}

int main()
{
    Node* root = new Node(15);
    root->left = new Node(20);
    root->right = new Node(35);
    root->left->left = new Node(5);
    cout<<"Largest BST in BT: " <<finder(root).ans<<endl;
    return 0;
}