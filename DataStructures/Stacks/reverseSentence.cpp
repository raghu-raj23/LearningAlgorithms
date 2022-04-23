#include <bits/stdc++.h> 
using namespace std;

void reverseSentence(string s){
    stack<string> st;
    for(auto i = 0; i < s.length(); i++){
        string word = "";
        while(s[i]!=' ' and i<s.length()){
            word+=s[i];
            i++;
        }
        st.push(word);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main()
{
    string s;
    // cin.ignore();
    getline(cin, s);
    reverseSentence(s);
    return 0;
}