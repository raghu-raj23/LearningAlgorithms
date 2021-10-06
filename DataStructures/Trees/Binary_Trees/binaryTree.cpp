/*

Properties of Binary trees:
-  Maximum nodes at level L = 2^L
-  Maximum nodes in a tree of height H is 2^H -1
-  For N nodes, minimum possible height or minimum number of levels are log2(N+1)
-  A binary tree with L leaves has at least log2(N+1)+1 number of levels

*/


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


int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    /*
    
            1
          /   \
          2    3

    */
    return 0;
}