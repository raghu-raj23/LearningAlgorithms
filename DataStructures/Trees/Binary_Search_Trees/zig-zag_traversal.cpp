/*

1. use 2 stacks - currentLevel and nextLevel
2. set a variable LeftToRight
3. if LeftToRight == true, push the left child of the node and then the right child
3.5 else push the right child and then the left child

*/

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

void zigzag(Node* root){
    if(root == NULL) return;

    stack<Node*> currentLevel, nextLevel;
    bool LeftToRight = true;
    currentLevel.push(root);
    while(!currentLevel.empty()){
        Node* top = currentLevel.top();
        currentLevel.pop();
        if(top){
            cout<<top->data<<" ";
            if(LeftToRight){
                if(top->left) nextLevel.push(top->left);
                if(top->right) nextLevel.push(top->right);
            }
            else{
                if(top->right) nextLevel.push(top->right);
                if(top->left) nextLevel.push(top->left);
            }
        }
        if(currentLevel.empty()){
            LeftToRight = !LeftToRight;
            swap(currentLevel, nextLevel);
        }
    }
}

int main()
{
    Node* root = new Node(12);
    root->left = new Node(9);
    root->right = new Node(15);
    root->left->left = new Node(5);
    root->left->right = new Node(10);
    zigzag(root);
    return 0;
}