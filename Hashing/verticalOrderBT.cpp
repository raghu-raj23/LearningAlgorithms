#include <bits/stdc++.h> 
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair

class Node{
    public:
    int key;
    Node *left, *right;
    Node(int k){
        key = k;
        left = right = NULL;
    }
};

void getVerticalOrder(Node *root, int hDist, map<int, vi> &m){
    
    if(root == NULL)
        return;
    m[hDist].PB(root->key);
    getVerticalOrder(root->left, hDist-1, m);
    getVerticalOrder(root->right, hDist+1, m);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    Node *root = new Node(10);
    root->left = new Node(7);
    root->right = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(11);
    root->right->left = new Node(14);
    root->right->right = new Node(6);
    map<int, vi> m;
    int hDist = 0;
    
    getVerticalOrder(root, hDist, m);

    for(auto &i: m){
        for(auto &j: i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}