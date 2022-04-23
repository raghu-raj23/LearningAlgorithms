#include <bits/stdc++.h> 
using namespace std;

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

bool getPath(Node *root, int target, vector<int> &path){
    if(root == NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data == target){
        return true;
    }
    if(getPath(root->left, target, path) || getPath(root->right, target, path)){
        return true;
    }
    path.pop_back();
    return false;
}

int LCA(Node* root, int n1, int n2){
    vector<int> path1, path2;
    if(!getPath(root, n1, path1) || !getPath(root, n2, path2)){
        return -1;
    }
    int i;
    for(i = 0; i < path1.size() && path2.size(); i++){
        if(path1[i] != path2[i])
            break;
    }
    return path1[i-1];
}

Node* LCA2(Node* root, int n2, int n1){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    Node* left = LCA2(root->left, n2, n1);
    Node* right = LCA2(root->right, n2, n1);
    if(left && right){
        return root;
    }
    if(left){
        return left;
    }
    return right;
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

    int n1 = 7, n2 = 6;
    // int lca = LCA(root, n1, n2);
    Node* lca = LCA2(root, n1, n2);
    if(lca == NULL){
        cout<<"No LCA"<<endl;
    }
    else{
        cout<<"LCA is "<<lca->data<<endl;
    }
    return 0;
}