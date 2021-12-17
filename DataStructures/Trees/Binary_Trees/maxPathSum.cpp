#include <bits/stdc++.h> 
using namespace std;

/*
for each node calculate:
1. Node value
2. Max path sum from left child + node value
3. Max path sum from right child + node value
4. Max of 2 + Max of 3 + node value
*/

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int maxPathSumUtil(Node *root, int &ans){
    if(root == NULL){
        return 0;
    }
    int left = maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right, ans);

    int nodeMax = max(max(root->data, root->data+left+right), max(root->data+left, root->data+right));

    ans = max(ans, nodeMax);

    int singlePathSum = max(root->data, max(root->data+left, root->data+right));

    return singlePathSum;
}

int maxPathSum(Node* root){
    int ans = INT_MIN;
    maxPathSumUtil(root, ans);
    return ans;
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<maxPathSum(root);
    return 0;
}