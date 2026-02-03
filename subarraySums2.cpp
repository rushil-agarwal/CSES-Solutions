#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

void solve(){
    int n;
    ll x; 
    cin >> n >> x;

    vector<ll> nums(n);
    for(int i=0; i<n; i++)
        cin >> nums[i];

    map<ll, int> hash;
    ll curr = 0, ans=0;
    
    hash[0] = 1;
    
    for(int i=0; i<n; i++){
        curr += nums[i];

        ll need = curr - x;

        ans += hash[need];
        hash[curr]++;
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
 //   cin >> t;
    while(t--)
        solve();

    return 0;
}