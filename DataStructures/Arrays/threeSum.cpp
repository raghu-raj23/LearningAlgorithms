#include <bits/stdc++.h> 
using namespace std;

int threeSum(vector<int> arr, int target){
    bool found = false;
    sort(arr.begin(), arr.end());
    for(int i =0;i<arr.size();i++){
        int low = i+1, hi = arr.size()-1;
        while(low<hi){
            int curr = arr[i] + arr[low] + arr[hi];
            if(curr==target){
                found = true;
            }
            if(curr<target){
                low++;
            }
            else
            hi--;
        }
    }
    return found ;
}
int main()
{
    int n,target;cin>>n>>target;
    vector<int> arr(n);
    for(auto &i:arr){
        cin>>i;
    }
    cout<<threeSum(arr,target)<<endl;
    return 0;
}