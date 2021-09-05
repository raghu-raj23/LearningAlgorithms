//  This is a question asked in Amazon 

#include <bits/stdc++.h> 
using namespace std;

int solve(int N){
    int count = 0;
    int upper_limit = (pow((2*N + 0.25),0.5) - 0.5)+1;
    for(int i =0; i<N; i++){
        N-=i;
        if(N%i == 0){
            count++;
        }
    }
    return count;}

int main()
{
    int n;
    cin>>n;
    return 0;
}