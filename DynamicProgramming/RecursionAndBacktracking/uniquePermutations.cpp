#include <bits/stdc++.h> 
using namespace std;

void helper(vector<int> nums, vector<vector<int>> &ans, int idx){
    if(idx == nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i =idx; i<nums.size(); i++){
        if(i != idx and nums[i] == nums[idx]){
            continue;
        }
        swap(nums[i], nums[idx]);
        helper(nums,ans,idx+1);
    }
    return;
}

vector<vector<int>> solve(vector<int> a){
    sort(a.begin(),a.end());
    vector<vector<int>> answer;
    helper(a, answer,0);
    return answer;
}

int main()
{
    int n; cin>>n;
    vector<int> a(n);
    for(auto &i:a)
        cin>>i;
    vector<vector<int>> ans = solve(a);
    for(auto v:ans){
        for(auto i:v){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}