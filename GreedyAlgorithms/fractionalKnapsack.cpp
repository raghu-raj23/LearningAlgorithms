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

bool compare(pi p1, pi p2){
    double v1 = (double)p1.F / p1.S;
    double v2 = (double)p2.F / p2.S;
    return v1 > v2;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<pi> a(N);
    FOR(i, N)
        cin >> a[i].F >> a[i].S;
    sort(a.begin(), a.end(), compare);
    int W;
    cin >> W;
    int ans = 0;
    FOR(i,N){
        if(W >= a[i].S){
            ans += a[i].F;
            W -= a[i].S;
            continue;
        }
        double valPerWeight = (double)a[i].F / a[i].S;
        ans += valPerWeight * W;
        W = 0;
        break;
    }
    cout<<ans<<endl;
    return 0;
}