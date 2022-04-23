#include <bits/stdc++.h> 
using namespace std;

int solve(int value[], int wt[], int n, int W){
    if(n==0 || W==0) return 0; 

    if(wt[n-1]>W){
        return solve(value, wt, n-1, W);
    }    
    // find the max between including the nth item in sack and not including it in the sack
    return max(solve(value, wt, n-1, W-wt[n-1])+ value[n-1], solve(value, wt, n-1, W));
}

int main()
{
    int wt[] = {10,20,30};
    int value[] = {100,50,150};
    int W = 50;
    cout<<solve(value, wt,3,W)<<endl;
    return 0;
}