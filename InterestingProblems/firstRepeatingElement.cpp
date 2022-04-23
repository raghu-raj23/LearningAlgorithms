/*
Given an array size n. Find first repeating element 
and the index of first repeating element is the smallest

Amazon/Oracle

eg 
7
1 5 3 4 3 5 6

ans -> 2(considering 1 indexing) 
*/

#include "bits/stdc++.h"
using namespace std;

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0; i<n;i++) cin>>arr[i];

    const int N = 1e6+2;
    int idx[N];
    memset(idx,-1,sizeof(idx));
    int minidx = INT_MAX;
    for(int i=0; i<n;i++){
        if(idx[arr[i]] != -1){
            minidx =min(minidx,idx[arr[i]]);
        }
        else{
            idx[arr[i]] = i;
        }
    }
    if(minidx==INT_MAX){
        cout<<"-1"<<endl;
    }
    else{
        cout<<minidx+1<<endl;
    }

    return 0;
}