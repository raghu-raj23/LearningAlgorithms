#include <bits/stdc++.h> 
using namespace std;

int solve(int n){
    if(n<=2){
        return n;
    }
    return solve(n-1)+ solve(n-2)*(n-1);
    
}

int main()
{
    cout<<solve(4)<<endl;
    return 0;
}