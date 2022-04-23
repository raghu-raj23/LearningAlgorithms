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
    int N;
    cin >> N;
    vi a(N);
    FOR(i, N)
    cin >> a[i];
    map<int,int> count;

    int prefSum = 0;
    FOR(i, N)
    {
        prefSum += a[i];
        count[prefSum]++;
    }
    int ans =0;
    for(auto &i: count){
        int c = i.S;
        ans += c*(c-1)/2;
        if(i.F == 0){
            ans += i.S;
        }
    }
    cout << ans << endl;
    return 0;
}