#include <bits/stdc++.h> 
using namespace std;

vector<int> stockSpan(vector<int> prices){
    vector<int> ans;
    stack<pair<int,int> > s;
    for(auto price:prices){
        int days = 1;
        while(!s.empty() and s.top().first <=price){
            days+=s.top().second;
            s.pop();
        }
        s.push({price, days});
        ans.push_back(days);
    }
    return ans;
}
int main()
{
    vector<int> arr = {100,80,60,70,60,75,85};
    vector<int> res = stockSpan(arr);
    for(auto i: res){
        cout<<i<<" ";
    }
    return 0;
}