/*
Heaps in the form of arrays: 
    Node -> index
    Parent -> floor((index) / 2)
    Left Clild -> 2 * (index)
    Right Child -> 2 * (index) + 1

    If no child exists, then the node is a leaf node. But if one child then add Null to the array in place of no node
*/

// push : O(log n)
// pop : O(log n)
// top : O(1)
// isEmpty : O(1)
// size : O(1)

#include <bits/stdc++.h>
using namespace std;

signed main(){
    priority_queue<int, vector<int>>pq;
    pq.push(5);
    pq.push(3);
    pq.push(7);
    cout<<pq.top()<<endl;

    priority_queue<int, vector<int>, greater<int>>pq2;
    pq2.push(5);
    pq2.push(3);
    pq2.push(7);
    cout<<pq2.top()<<endl;

    return 0;
}