/* number of visitors for n consecutive days
A day is record breaking if:
- number of visitors for the day is strictly larger than number of visitors on each of the previous days
- Either it is the last day or the number of visitors for the day is strictly larger than number of visitors on the following day.

- First day could be a record breaking day 

Find the number of record breaking days
*/

#include "bits/stdc++.h"
#include "climits"
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i =0;i<n;i++) cin>>arr[i];
    if(n==1){
        cout<<"1"<<endl;
        return 0;
    }
    int ans = 0;
    int mx = -1;
    for(int i = 0;i<n;i++){
        if(arr[i]>mx && arr[i]>arr[i+1]){
            ans++;
        }
        mx = max(arr[i], mx);
    }
    cout<<ans<<endl;

    return 0;
}