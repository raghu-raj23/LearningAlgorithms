/*
For a given integer N, find the maximum number of perfect numbers in a subarray of size K.

Perfect number is a number if it is equal to the sum of its proper divisors except for the number itself.
*/

#include <bits/stdc++.h> 
using namespace std;

bool isPerfect(int a){
    int sum = 1;
    for(int i = 2; i< sqrt(a); i++){
        if(a % i == 0){
            if(i == a/i){
                sum +=i;
            }
            else{
                sum += i + a/i;
            }
        }
    }
    if(sum == a && a != 1){
        return true;
    }
    return false;
}

int maxSum(int arr[], int n, int k){
    if(n<k) return -1;

    int res=0;
    for(int i=0;i<k;i++){
        res+=arr[i];
    }
    int sum = res;
    for(int i =k; i<n;i++){
        sum += arr[i] - arr[i-k];
        res = max(sum, res);
    }
    return res;
}

int maxPerfectSubarray(int arr[], int n, int k){
    for(int i =0; i<n; i++){
        if(isPerfect(arr[i])){
            arr[i] = 1;
        }
        else{
            arr[i] = 0;
        }
    }
    return maxSum(arr, n, k);
}

int main()
{
    int arr[] = {28,2,3,6,496, 99, 8128, 24};
    int k = 4;
    int n = 8;
    cout<< maxPerfectSubarray(arr, n, k)<<endl;
    return 0;
}