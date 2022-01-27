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

vector<Node*> catalan_BST(int start, int end){
    vector<Node*> trees;
    if(start > end){
        trees.push_back(NULL);
        return trees;
    } 
    for(int i = start; i<= end; i++){
        vector<Node*> leftSubTrees = catalan_BST(start, i-1);
        vector<Node*> rightSubTrees = catalan_BST(i+1, end);
        
        for(int j =0; j<leftSubTrees.size(); j++){
            Node* left = leftSubTrees[j];
            for(int k =0; k<rightSubTrees.size(); k++){
                Node* right = rightSubTrees[k];
                Node* node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }
    return trees;
}

void preorder(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    vector<Node*> totalTrees = catalan_BST(1, 3);
    for(int i =0; i<totalTrees.size(); i++){
        cout<<"Tree "<<i+1<<" : ";
        preorder(totalTrees[i]);
        cout<<endl;
    }
    return 0;
}