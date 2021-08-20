#include <bits/stdc++.h>
using namespace std;

bool sorted(int arr[], int n){
    if(n==1)
    return true;

    bool rest = sorted(arr+1, n-1);
    return(arr[0]<arr[1] && rest);
}
// Same method can be used to find first occurance of a element in the array.

// For last occurance 

int lastoccurrence(int arr[], int n, int i, int key){
    if(n==i) return -1;
    int rest = lastoccurrence(arr, n, i+1, key);
    if(rest != -1){
        return rest;
    }
    if(arr[i] ==key) return i;

    return -1;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    cout<<sorted(arr, 8)<<endl;

    return 0;
}