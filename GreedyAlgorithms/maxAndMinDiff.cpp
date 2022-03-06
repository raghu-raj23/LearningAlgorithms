/*
Given an array A, of n elements. Remove exactly n/2 elements from A and add to another array B.
Find max and min values of the differences between these two arrays.
∑ abs(A[i] - B[i])

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
    cin.tie(0);
    int N;
    cin >> N;
    vi a(N);
    FOR(i, N)
    cin >> a[i];
    sort(a.begin(), a.end());
    ll mn = 0, mx = 0;
    for(int i =0; i<N/2;i++){
        mx += (a[i+ N/2] - a[i]);
        mn += (a[2*i+1] - a[2*i]);
    }
    cout<<"min: "<<mn<<" max: "<<mx<<endl;
    return 0;
}