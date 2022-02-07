#include <bits/stdc++.h> 
using namespace std;

void heapify(vector<int> &arr, int n, int i){
    int maxIdx = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left <n && arr[left] > arr[maxIdx]){
        maxIdx = left;
    }
    if(right <n && arr[right] > arr[maxIdx]){
        maxIdx = right;
    }
    if(maxIdx != i){
        swap(arr[i], arr[maxIdx]);
        heapify(arr, n, maxIdx);
    }
}

void heapsort(vector<int> &arr){
    int n = arr.size();

    for(int i = n/2 -1; i>=0; i--){
        heapify(arr, n, i);
    }

    for(int i = n-1; i>0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    return ;
}

int main()
{
    int n;cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    heapsort(arr);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}