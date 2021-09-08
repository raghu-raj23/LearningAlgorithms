#include <bits/stdc++.h> 
using namespace std;

void solve(int arr[],int n){
    int maxi = arr[0];
    
    // find the max element of the array to get the size of the count array

    for(int i = 0; i<n;i++){
        maxi = max(maxi,arr[i]);
    }

    // traverse the array and find the count of each element and store in respective index(same as element)

    int count[10] = {0};
    for(int i = 0; i<n;i++){
        count[arr[i]]++;
    }

    // add the count of the element to the sum of the count of the previous element
    for(int i = 1; i<=maxi; i++){
        count[i]+=count[i-1];
    }
    // Traversing from the end, decrement the count of the element and use it as the index for the solution array
    int ans[n];
    for(int i = n-1; i>=0; i--){
        ans[--count[arr[i]]] = arr[i];
    }

    
    for(int i=0;i<n; i++){
        arr[i] = ans[i];
    }
}

int main()
{
    int n;cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    solve(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}