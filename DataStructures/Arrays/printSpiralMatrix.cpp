#include "bits/stdc++.h"
using namespace std;
const int psn=3,psm=3;
void printSpiral(int arr[psn][psm], int n,int m){
    int row_start =0, row_end = n-1,col_start = 0, col_end = m-1;
    while(row_start<= row_end && col_start<=col_end){
        // for row start
        for(int col = col_start; col<= col_end; col++){
            cout<<arr[row_start][col]<<" ";
        }
        row_start++;
        // for column end
        for(int row = row_start; row<= row_end; row++){
            cout<<arr[row][col_end]<<" ";
        }
        col_end--;
        // for row end
        for(int col = col_end; col>= col_start; col--){
            cout<<arr[row_end][col]<<" ";
        row_end--;
        }
        // for cloumn start
        for(int row = row_end; row>= row_start; row--){
            cout<<arr[row][col_start]<<" ";
        }
        col_start++;
    }
}


int main(){
    int arr[psn][psm];
    for(int i=0;i<psn;i++){
        for(int j =0;j<psm;j++)
        cin>>arr[i][j];
    }
    printSpiral(arr, psn, psm);    

    return 0;
}