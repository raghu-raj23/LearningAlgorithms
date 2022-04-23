#include <bits/stdc++.h> 
using namespace std;

// when bigger tile as 2xn and smaller 2X1

int solve(int n){
    if(n == 0) return 0;
    if(n==1) return 1;

    return solve(n-1) + solve(n-2);
}

int main()
{
    cout<<solve(4)<<endl;
    return 0;
}