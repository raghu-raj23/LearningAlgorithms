/*
Given unsorted array of size N find subarray which adds to a given number S.

n=5, s = 12
A = {1,2,3,,7,5}
Output starting and ending indexes
*/

#include "bits/stdc++.h"
using namespace std;

int main(){
    int n,s;cin>>n>>s;
    int arr[n];
    for(int k =0; k<n; k++)cin>>arr[k];

    int i =0, j =0, st = -1, en = -1, sum =0;

    while(j<n && sum+arr[j]<= s){
        sum+=arr[j];
        j++;
    }
    if(sum==s){
        cout<<i+1<<" "<<j<<endl;
        return 0;
    }
    while(j<n){
        sum+=arr[j];
        while(sum>s){
            sum-=arr[i];
            i++;
        }
        if(sum==s){
            st = i+1;
            en = j+1;
            break;
        }
        j++;
    }
    cout<<st<<" "<<en<<endl;
    return 0;
}