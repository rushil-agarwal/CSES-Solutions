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

    sort(vec.begin(), vec.end());

    ll median;

    if(n&1)
        median = vec[n/2];
    else
        median = (vec[n/2] + vec[n/2-1])/2;

    ll ans = 0;

    for(int i=0; i<n; i++)
        ans += abs(vec[i]-median);

    cout << ans << endl;
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