#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

void solve(){
    int n; cin >> n;
    vector<ll> vec(n);

    for(int i=0; i<n; i++)
        cin >> vec[i];

    ll ans = LLONG_MIN, curr = 0;

    for(int i=0; i<n; i++){
        curr += vec[i];

        ans = max(ans, curr);

        if(curr < 0)
            curr = 0;
    }
    
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    //cin >> t;
    while(t--)
        solve();

    return 0;
}