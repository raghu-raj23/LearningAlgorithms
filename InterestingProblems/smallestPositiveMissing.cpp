/*
Find the smallest positive number missing from the array of n integers

*/

#include "bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    const int N = 1e6 + 2;
    bool check[N];
    memset(check, 0, sizeof(check));
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > -1)
        {
            check[arr[i]] = 1;
        }
    }
    int ans = -1;
    for (int i = 1; i < N; i++)
    {
        if (check[i] == 0)
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}