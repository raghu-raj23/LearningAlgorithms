/*

Given an asc sorted array that has been rotated from a pivot point and an element X. Search for X in the array with complexity less than that of linear search.

*/

#include <bits/stdc++.h> 
using namespace std;

int searchInRotatedArray(int arr[], int key, int left, int right){
    if(left > right) return -1;
    int mid = (left+right)/2;
    if(arr[mid] == key){
        return mid;
    }
    if(arr[left] <= arr[mid]){// this is to find the point of pivot
        if(key >= arr[left] && key <= arr[mid]){
            return searchInRotatedArray(arr, key, left, mid-1);
        }
        return searchInRotatedArray(arr, key, mid+1, right);
    }
    if(key >= arr[mid] && key <= arr[right]){
        return searchInRotatedArray(arr, key, mid+1, right);
    }
    return searchInRotatedArray(arr, key, left, mid-1);
}

int main()
{
    int arr[] = {6,7,8,9,10,1,2,5};
    int key = 7;
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = searchInRotatedArray(arr, key, 0, n-1);
    (ans == -1)? cout<<"Not Found"<<endl:cout<<"Index of the element: "<<ans<<endl;
    return 0;
}