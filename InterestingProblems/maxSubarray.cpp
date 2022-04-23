#include "bits/stdc++.h"
using namespace std;
int kadane(int *arr, int n){
    int curr = 0;
    int maxSum = INT_MIN;
    for(int i=0;i<n;i++){
        curr += arr[i];
        if(curr<0){
            curr =0;
        }
        maxSum =max(maxSum,curr);
    }
    return maxSum;
}

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int nowrap = kadane(arr, n);
    int wrap;
    int totsum = 0;
    for(int i = 0; i< n; i++){
        totsum += arr[i];
        arr[i] =- arr[i];
    }
    wrap = totsum + kadane(arr,n);
    cout<<max(wrap, nowrap)<<endl;
    return 0;
}