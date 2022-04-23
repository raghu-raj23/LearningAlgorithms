#include <bits/stdc++.h> 
using namespace std;

int get_max_area(vector<int> a){
    int n = a.size(), ans = 0, i = 0,curr = 0;
    stack<int> st;
    while(i<n){
        while(!st.empty() and a[st.top()]>=a[i]){
            int t = st.top();
            st.pop();
            curr = a[t]*(st.empty() ? i : i-st.top()-1);
            ans = max(ans,curr);
        }
        st.push(i);
        i++;
    }
    while(!st.empty()){
        int t = st.top();
        st.pop();
        curr = a[t]*(st.empty() ? n :n-st.top()-1);
        ans = max(ans, curr);
    }
    return ans;
}
int main()
{
    vector<int> a = {2,1,5,6,2,3};
    cout<<get_max_area(a);
    return 0;
}