#include <bits/stdc++.h> 
using namespace std;

int main()
{
    int k; cin>>k;
    vector<vector<int>> v(k);
    for(int i =0; i< k; i++){
        int size;
        cin>>size;
        v[i] = vector<int>(size);
        for(int j = 0; j< size; j++){
            cin>>v[i][j];
        }
    }
    vector<int> idx(k, 0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    for(int i=0; i<k; i++){
        pq.push({v[i][0], i});
    }

    vector<int> ans;

    while(!pq.empty()){
        pair<int,int> x = pq.top();
        pq.pop();
        ans.push_back(x.first);
        if(idx[x.second] + 1 < v[x.second].size()){
            pq.push({v[x.second][idx[x.second] + 1], x.second});
        }
        idx[x.second]++;
    }
    for(int i =0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}