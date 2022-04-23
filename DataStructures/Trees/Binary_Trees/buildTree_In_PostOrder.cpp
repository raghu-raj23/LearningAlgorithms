
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

int search(int inorder[], int start, int end, int curr){
    for(int i=start; i<=end; i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}

Node* buildTree(int postorder[], int inorder[], int start, int end){
    static int index = end;
    if(start>end){
        return NULL;
    }
    int curr = postorder[index]; // selecting an element in the postorder array
    index--;
    Node* node = new Node(curr); // creating a new node with the current element
    if(start == end){
        return node;
    }
    int pos = search(inorder, start, end, curr); // searching the position of the element in inorder array
    node->right = buildTree(postorder, inorder, pos+1, end); // building the right subtree
    node->left = buildTree(postorder, inorder, start, pos-1); // building the left subtree
    return node;
}

void inorderPrint(Node* root){
    if(root == NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main()
{
    int postorder[] = {4,2,5,3,1};
    int inorder[] = {4,2,1,5,3};

    Node* root = buildTree(postorder, inorder, 0, 4);
    inorderPrint(root);

    return 0;
}
