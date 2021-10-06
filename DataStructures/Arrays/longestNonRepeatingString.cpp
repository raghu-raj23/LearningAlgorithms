#include <bits/stdc++.h> 
using namespace std;

int main()
{
    string s;cin>>s;
    vector<int> alpha(256, -1);
    int maxLen = 0, start = -1;
    for(int i=0; i<s.size(); i++){
        if(alpha[s[i]] > start){
            start = alpha[s[i]];
        }
        alpha[s[i]] = i;
        maxLen = max(maxLen, i-start);
    }
    cout<<maxLen<<endl;
    return 0;
}