#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int start, int end, int mid){
    int n1 = mid - start+1;
    int n2 = end-mid;
    int arr1[n1];
    int arr2[n2];
    for(int i = 0; i < n1; i++){
        arr1[i] = arr[start+i];
    }
    for(int i =0; i < n2;i++){
        arr2[i] = arr[mid+1+i];
    }
    int a=0,b=0,c=start;
    while(a<n1 and b<n2){
        if(arr1[a]<arr2[b]){
            arr[c] = arr1[a];
            a++;c++;
        }
        else{
            arr[c] = arr2[b];
            b++;c++;
        }
    }
    while(a<n1){
        arr[c] = arr1[a];
        c++;a++;
    }
    while(b<n2){
        arr[c] = arr2[b];
        c++;b++;
    }
}

void MergeSort(int arr[], int start, int end){
    if(start<end){
        int mid = (start+end)/2;
        MergeSort(arr,start,mid);
        MergeSort(arr,mid+1,end);

        merge(arr, start, end, mid);
    }
}

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    MergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}