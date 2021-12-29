#include <bits/stdc++.h> 
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;
    Node(int val){
        this->data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* search(Node* root, int val){
    if(root == NULL) return NULL;
    if(root->data == val) return root;
    if(root->data<val) return search(root->right, val);
    if(root->data>val) return search(root->left, val);
}
// delete

Node* inorderSucc(Node* root){
    Node* curr = root;
    while(curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

Node* deleteInBST(Node* root, int key){
    if(key<root->data){
        root->left = deleteInBST(root->left, key);
    }
    else if(key>root->data){
        root->right = deleteInBST(root->right, key);
    }
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            delete(root);
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete(root);
            return temp;
        }
        else{
            Node* temp = inorderSucc(root->right);
            root->data = temp->data;
            root->right = deleteInBST(root->right, temp->data);
        }
    }
}

int main()
{
    Node* root = NULL;
    root = insert(root, 5);
    insert(root, 2);
    insert(root, 3);
    insert(root, 9);
    insert(root, 1);
    insert(root, 8);
    insert(root, 7);
    inorder(root);

    (search(root, 5)) ? cout<<"Found"<<endl : cout<<"Not Found"<<endl;
    root = deleteInBST(root, 5);
    (search(root, 5)) ? cout<<"Found"<<endl : cout<<"Not Found"<<endl;
    return 0;
}