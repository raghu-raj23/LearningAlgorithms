#include <bits/stdc++.h>
using namespace std;

string removeDupes(string s){
    if(s.length()==0) return "";

    char ch = s[0];
    string ans = removeDupes(s.substr(1));

    if(ch==ans[0]){
        return ans;
    }
    return ch+ans;
}


int main(){
    cout<<removeDupes("aaabbbcccddd");
    return 0;
}