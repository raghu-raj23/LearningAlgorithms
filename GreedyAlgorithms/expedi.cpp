/*

A group of cows grabbed a truck and ventured on an expedition deep into the jungle. The truck leaks 1 unit of fuel per unit of distance traveled. 

To repair the truck, the cows need to drive to the nearest town on the way there are N  fuel stops where they can aquire additional fuel(1- 100 units).

The cows need to make the minimum number of stops to get to the town.

capacity of truck is infinite.

Initial unit of fuel is P 
Initial distance from town is D

Determine the minimum number of stops needed to get to the town.

SOLUTION:

- create a max heap storing the fuels available at the stops that we have traversed

- sort stops on basis of distance based on initaial distance from truck

- iterate on stops, and when truck becomes empty take fuel from maxheap and add to the truck

- maintain count of steps from which we have taken fuel
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
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<pi> a(N); // distance from town, fuel capacity of stop
        FOR(i, N)
        cin >> a[i].F >> a[i].S;
        int l, p; cin>>l>>p;
        // make stops distance from truck
        FOR(i,N){
            a[i].F = l - a[i].F;
        }
        sort(a.begin(), a.end());

        int ans = 0;
        int currFuel = p;
        priority_queue<int, vector<int>> pq;
        bool flag = 0;

        FOR(i,N){
            if(currFuel >= l){
                break;
            }
            while(currFuel < a[i].F){
                if(pq.empty()){
                    flag = 1;
                    break;
                }
                ans++;
                currFuel += pq.top();
                pq.pop();
            }
            if(flag){
                break;
            }
            pq.push(a[i].S);
        }
        if(flag){
            cout<<"-1"<<endl;
            continue;
        }
        while(!pq.empty() and currFuel < l){
            ans++;
            currFuel += pq.top();
            pq.pop();
        }
        if(currFuel < l){
            cout<<"-1"<<endl;
            continue;
        }
        cout<<ans<<endl;
    }
    return 0;
}