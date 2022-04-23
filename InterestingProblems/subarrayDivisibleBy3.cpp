/*
For a given array and an integer K, check if any subarray of size K exists in the array such that the sum of elements in the subarray form a number divisible by 3.
*/

#include <bits/stdc++.h> 
using namespace std;

void subArrayDivisible(vector<int> arr, int k){
    pair<int,int> ans;
    int sum = 0;
    for(int i = 0; i< k;i++){
        sum += arr[i];
    }
    bool found = false;
    if(sum % 3 == 0){
        ans = make_pair(0, k-1);
        found = true;
    }
    for(int i =k; i < arr.size(); i++){
        if(found){
            break;
        }
        sum += arr[i] - arr[i-k];
        if(sum%3 == 0){
            ans = make_pair(i-k+1, i);
            found = true;
        }
    }
    if(!found){
        ans = make_pair(-1, 0);
    }
    if(ans.first == -1) cout<<"No such subarray available in the givven array."<<endl;
    else cout<<"The minimum subarray is "<<endl;
    for(int i = ans.first; i<=ans.second; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> arr = {84,23,45,12,56,82};
    int k = 3;
    subArrayDivisible(arr, k);
    return 0;
}