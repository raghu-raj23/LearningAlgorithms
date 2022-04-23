#include "bits/stdc++.h"
using namespace std;
int main(){
    int n1, n2, target;
    cin >>n1>>n2>>target;
    int arr1[n1][n2];
    for(int i=0; i<n1; i++) {
        for(int j=0; j<n2; j++)
        cin>>arr1[i][j];
    }
    int r = 0, c = n2-1;
    bool found = false;
    while(r<n2 && c>=0){
        if(arr1[r][c] == target) {
            found = true;
        }
        if(arr1[r][c] > target){
            c--;
        }
        else{
            r++;
        }
    }
    if(found==true)
        cout<<"found";
    else
    cout<<"not found"<<endl;
    return 0;
}