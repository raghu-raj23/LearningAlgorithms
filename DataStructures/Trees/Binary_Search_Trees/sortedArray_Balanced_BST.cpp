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

Node* builder(int arr[], int start, int end){
    if(start > end)
        return NULL;
    
    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);

    root->left = builder(arr, start, mid - 1);
    root->right = builder(arr, mid + 1, end);
    return root;
}

void preorder(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int arr[] = {10,20,30,40,50,60,70,80,90,100};
    Node* root = builder(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);
    preorder(root);
    return 0;
}