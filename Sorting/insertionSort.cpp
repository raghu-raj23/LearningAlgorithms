#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int size){
    for(int j = 1; j<size;j++) {
        int key = arr[j];
        int i = j-1;
        while(i> -1 && arr[i]>key){
            arr[i+1] = arr[i];
            i-=1;
        }
        arr[i+1] = key;
        // for(int k = 0; k<size; k++) cout<<arr[k]<<endl;
    }    
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++) cin>>arr[i];
    insertionSort(arr, n);
    for(int i = 0; i<n; i++) cout<<arr[i]<<" ";    
    return 0;
}