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

const int S = 1e5+2;
bool visited[S] = {0};
vi adj[S];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    int x, y;
    FOR(i, M){
        cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(auto j: adj[node]){
            if(!visited[j]){
                q.push(j);
                visited[j] = true;
            }
        }
    }
    
    return 0;
}