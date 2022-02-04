/*
For a given array and ana integer x, check if any subarray of size K exists in the array such taht concatnation of elements form a palindrome.
*/

#include <bits/stdc++.h> 
using namespace std;

bool isPalindrome(int num){
    int temp = num;
    int rev = 0;
    while(num){
        rev = rev*10 + num%10;
        num /= 10;
    }
    return rev == temp;
}

int palindromeSubarray(vector<int> arr, int k){
    int num = 0;
    for(int i = 0; i<k;i++){
        num = num*10 + arr[i];
    }
    if(isPalindrome(num)){
        return 0;
    }
    for(int i = k; i<arr.size(); i++){
        num = (num % (int)pow(10, k-1))*10 + arr[i];
        if(isPalindrome(num)){
            return i-k+1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {2,3,5,1,1,5};
    int k = 4;
    int ans = palindromeSubarray(arr, k);
    ans == -1 ? cout << "No subarray found" : cout << "Subarray found starting from index " << ans<<endl;
    for(int i =ans; i< ans+k; i++){
        cout << arr[i] << " ";
    }

    return 0;
}