#include <bits/stdc++.h> 
using namespace std;
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) < (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) > (c); (a)--)
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
    vector<vi> a;
    FOR(i, N){
        int start, end;
        cin>>start>>end;
        a.PB({start, end});
    }
    sort(a.begin(), a.end(), 
    [&](vector<int> &a, vector<int> &b){ // lambda function in C++
        return a[1] < b[1];
    });
    int take = 1;
    int end = a[0][1];
    FORL(i, 1, N){
        if(a[i][0] >= end){
            take++;
            end = a[i][1];
        }
    }
    cout<<take<<endl;
    return 0;
}