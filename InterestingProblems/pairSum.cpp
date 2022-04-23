/*

Check if there are two elements in an array such that their sum is eaual to a given number k 

*/
#include <bits/stdc++.h>
using namespace std;

bool pairSum(int *arr,  int n, int k){
    sort(arr,arr+n);
    int l =0, r = n-1;
    while(l<r){
        if(arr[l]+arr[r] == k){
            cout<<l<<" "<<r<<endl;
            return true;
        }
        else if(arr[l]+ arr[r] <k){
            l++;
        }
        else if(arr[l]+ arr[r] >k){
            r--;
        }
    }
    return(false);
}

int main(){
    int n,k;cin>>n>>k;
    int arr[n];for(int i =0;i<n;i++)cin>>arr[i];
    cout<<pairSum(arr,n,k);
    return 0;
}