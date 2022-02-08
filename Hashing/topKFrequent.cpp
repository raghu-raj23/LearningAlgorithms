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
    int N,k;
    cin >> N >> k;
    vi a(N);
    FOR(i, N)
    cin >> a[i];
    map<int,int> m;
    FOR(i, N){
        int presentSize = m.size();
        if(m[a[i]] == 0 && presentSize == k){
            break;
        }
        m[a[i]]++;
    }
    vector<pi> ans;

    for(auto it: m){
        if(it.S != 0)
            ans.PB(MP(it.S, it.F));
    }
    sort(ans.begin(), ans.end(), greater<pi>());
    
    for(auto i: ans){
        cout << i.S << " " << i.F << endl;
    }
    return 0;
}