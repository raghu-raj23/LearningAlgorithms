#include <bits/stdc++.h> 
using namespace std;

/* 

    Catalan Numbers:
    Number sequence that often involve recursively defined objects

    Their closed form is:

        Cn = (1/n+1) * 2nCn = Σ Ci * Cn-i,  i = 0 to n-1

        C0 = 1, C1 = 1, C2 = C0*C1 + C1*C0 = 2 .............

*/

int catalan(int n){
    if(n <= 1){
        return 1;
    }
    int result = 0;
    for(int i = 0; i < n; i++){
        result += catalan(i)*catalan(n-i-1);
    }
    return result;
}

int main(){
    for(int i =0; i< 10; i++){
        cout<<catalan(i)<<" ";
    }
    return 0;
}

/*

Applications:
    - POssible no of BSTs from n nodes
    - Parenthesis/ bracket combinations
    - Possible forests
    - Ways of triangulations
    - Possible paths in matrix
    - Dividing a circle using n chords
    - Dyck words of given length .........

*/