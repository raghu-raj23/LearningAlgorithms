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

const int S = 1e5+2, MOD = 1e9+7;
vi adj[S];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    // n -> num of nodes , m -> num of edges
    cin >> N>>M;
    vector<vi> adjm(N+1, vi(N+1, 0)); // adjacency matrix
    FOR(i, N){
        int x,y;
        cin >> x >> y;
        adjm[x][y] = 1;
        adjm[y][x] = 1;
    }
    cout<< "Adjacency Matrix" << endl;
    FORL(i,1, N){
        FORL(j,1, N){
            cout << adjm[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl<<endl;
    
    cin >> N >> M;
    FOR(i, M){
        int x,y;
        cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }
    cout<< "Adjacency List" << endl;
    FOR(i, N+1){
        cout << i << " -> ";
        for(auto j: adj[i]){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}