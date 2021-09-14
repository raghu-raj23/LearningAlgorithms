#include <bits/stdc++.h> 
using namespace std;

/* 
here the number of inversions are found as:
the number of elements to the right of an element that ate lesser than the element
so if we take 3 2 1 as the array
then (3,2), (3,1) (2,1) are the inversions
*/

long long merge(int arr[], int l,int mid,int r){
    int n1 = mid-l+1;
    int n2 = r-mid;
    long long inv = 0;
    int a[n1]; int b[n2];
    for(int i=0;i<n1;i++) a[i] = arr[i+l];
    for(int i=0;i<n2;i++) b[i] = arr[mid+i+1];
    int i=0,j=0,k=l;
    while(i<n1 and j<n2){
        if(a[i]<=b[j]){
            arr[k] = a[i];
            k++;i++;
        }
        else{
            arr[k] = b[j];
            inv+= n1-i;
            k++;j++;
        }
        while(i<n1){
            arr[k] = a[i];
            i++;k++;
        }
        while (j<n2){
            arr[k] = b[j];
            j++;k++;
        }
    }
    return inv;
}

long long solve(int arr[], int l, int r){
    long long inv = 0;
    if(l<r){
        int mid = (l+r)/2;
        inv += solve(arr, l,mid);
        inv += solve(arr,mid+1,r);
        inv += merge(arr, l,mid,r);
    }
    return inv;
    }

int main()
{
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<solve(arr,0,n-1);
    return 0;
}