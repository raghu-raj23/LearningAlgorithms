/*

Collision in Hashing is handled in two ways:
    - Separate chaining:
        if collision create chain of linked list
        search time: O(n)
        Load factor: n/b
    - Opern Addressing:
        if collision do probing P(k).
        -- Linear probing:
            P(k) = a*k + b
        -- Quadratic probing:
            P(k) = a*k^2 + b*k + c
        -- Double hashing:
            P(k,x) = k*h1(x), h2(x) is a secondary hash function

*/

/*
Hashing using STL:
Maps (key, value):
- insertion: O(log(n))
- search: O(log(n))
- deletion: O(log(n))
- Implementation: Red-black Trees

Unordered Maps:
- insertion: O(1)
- search: O(1)
- deletion: O(n)
- Implementation: Hash Table
*/

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
    map<int,int> m;
    m[8] = 1;
    cout<<m[8]<<endl;
    return 0;
}