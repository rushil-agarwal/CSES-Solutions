#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

void solve(){
    int n; ll tasks;
    
    cin >> n >> tasks;

    
    vector<ll> machines(n);
    for(int i=0; i<n; i++)
        cin >> machines[i];

    sort(machines.begin(), machines.end());

    ll left = 0, right = 1LL*tasks*machines[0];
    ll ans = LLONG_MAX;

    while(left <= right){
        ll mid = (left+right)/2;

        ll done=0;

        for(int i=0; i<n; i++){
            done += mid/machines[i];
        }

        if(done >= tasks){
            ans = mid;
            right = mid-1;
        }else 
            left = mid+1;
    }
    
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
   // cin >> t;
    while(t--)
        solve();

    return 0;
}