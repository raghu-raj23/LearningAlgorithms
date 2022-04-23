#include "bits/stdc++.h"
using namespace std;

void sieveOfEratosthenes(int n){
    int prime[100] = {0};
    for(int i =2;i<=n;i++){
        if(prime[i]==0){
            for(int j = i*i;j<=n;j+=i){
                prime[j] = 1;
            }
        }
    }
    for(int i = 2;i<=n;i++){
        if(prime[i]==0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

int main(){
    sieveOfEratosthenes(30);
    return 0;
}