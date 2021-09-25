#include <bits/stdc++.h> 
using namespace std;

/*----------------------------------------------------------------
- when there is any alphabet append to result string
- if its a ( then push it to stack 
- if its a ) then pop till top is (
- if its operator then check precedence pop from stack till there 
    is a operator with lower precedence is found on the top of stack 
    then push the operator to stack
        i.e if the incoming operator is having higher precedence 
        than the operator at the top of stack then the incoming operator 
        is pushed directly to stack but if it has lower precedence than 
        the operator at the top of stack then pop from the stack till 
        there is a operator with lower precedence
----------------------------------------------------------------*/

int precedence(char c){
    switch(c){
        case '^': return 3;
        break;
        case '*': return 2;
        break;
        case '/': return 2;
        break;
        case '+': return 1;
        break;
        case '-': return 1;
        break;
        default: return -1;
    }
}

string infixToPostfix(string s){
    stack<char> st;
    string result;
    for(int i=0; i<s.length(); i++){
        if(s[i]<='z' and s[i]>='a' or (s[i]>='A' and s[i]<='Z')){
            result+=s[i];
        }
        else if(s[i] == '('){ 
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() and st.top()!= '('){
                result+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() and precedence(st.top())>precedence(s[i])){
                result+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    return result;
}
int main()
{
    cout<<infixToPostfix("(a-b/c)*(a/k-l)")<<endl;
    return 0;
}