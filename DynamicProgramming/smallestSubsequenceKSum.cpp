#include <bits/stdc++.h> 
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n>>k;
    vi a(n);
    FOR(i,n)
    {
        cin >> a[i];
    }

    priority_queue<int, vi> pq;
    FOR(i,n){
        pq.push(a[i]);
    }

    int sum = 0, count =0;
    while(!pq.empty()){
        sum+= pq.top();
        pq.pop();
        count++;
        if(sum >= k)
            break;
    }
    if(sum < k){
        cout<<"-1"<<endl;
    }
    else{
        cout<<count<<endl;
    }
    return 0;
}