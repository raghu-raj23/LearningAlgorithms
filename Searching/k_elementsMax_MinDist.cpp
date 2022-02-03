/*

Given is an array with n elements that represent n positions along a stright line. Find K elements that are the maximum of the minimum distance from each other.

*/

#include <bits/stdc++.h> 
using namespace std;

bool ifFeasable(int mid, int arr[], int n, int k){
    int pos = arr[0], elements = 1;
    for(int i =1; i <n;i++){
        if(arr[i] - pos >= mid){
            pos = arr[i];
            elements++;
            if(elements>=k) return true;
        }
    }
    return false;
}

int largestMinDist(int arr[], int n, int k){
    sort(arr, arr+n);

    int result = -1;
    int left = 1, right = arr[n-1];

    while(left < right){
        int mid = (left + right)/2;
        if(ifFeasable(mid, arr, n, k)){
            result = max(result, mid);
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    return result;
}

int main()
{
    int arr[] = {1,2,8,4,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k =3;
    cout<<"The largest minimum distancce will be : "<<largestMinDist(arr, n, k)<<endl;
    return 0;
}