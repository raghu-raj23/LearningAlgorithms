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

bool areSame(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL) return true;
    else if(root1 == NULL || root2 == NULL) return false;
    else{
        bool condition1 = root1->data == root2->data;
        bool condition2 = areSame(root1->left, root2->left);
        bool condition3 = areSame(root1->right, root2->right);
        return condition1 && condition2 && condition3;
    }
}

int main()
{
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(3);
    
    Node* root2 = new Node(6);
    root2->left = new Node(3);
    root2->right = new Node(10);
    
    areSame(root2, root1) ? cout<<"Same"<<endl: cout<<"Not Same"<<endl;
    return 0;
}