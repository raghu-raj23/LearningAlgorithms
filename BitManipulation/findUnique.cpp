#include "bits/stdc++.h"
using namespace std;

int setBit(int n, int pos){
    return ((n | (1<<pos)));
}

int getBit(int n, int  pos){
    return ((n & (1<<pos))!=0);
}

void findTwoUnique(int arr[], int n){
    int xorsum = 0, newxor=0;
    for(int i=0; i<n; i++){
        xorsum = xorsum^arr[i];
    }
    int tempxor = xorsum;
    int setbit =0, pos = 0;
    while(setbit!= 1){
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum>>1;
    }
    for(int i = 0; i<n; i++){
        if(getBit(arr[i], pos-1)){
            newxor = newxor^arr[i];
        }
    }
    cout<<newxor<<endl;
    cout<<(tempxor^newxor)<<endl;
}

int uniqueInTriplets(int arr[], int n){
    int result=0;
    for(int i=0; i<64; i++){
        int sum =0;
        for(int j=0; j<n; j++){
            if(getBit(arr[j], i)){
                sum++;
            }
        }
        if(sum%3 !=0){
            result = setBit(result, i);
        }
    }
    return result;
}

int main(){
    // int n;cin>>n;
    // int arr[n];
    // for(int i = 0; i<n; i++) cin>>arr[i];
    // int xorsum = 0;
    // for(int i = 0; i<n;i++){
    //     xorsum = xorsum^arr[i];        
    //     }
    // cout<<xorsum<<endl;
    
    // findTwoUnique(arr, n);
    int arr[]= {1,2,3,4,1,2,3,1,2,3};
    cout<<uniqueInTriplets(arr, 10)<<endl;


    return 0;
}