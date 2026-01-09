#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

void solve(){
    int n, ans = 0; cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> exit;
    vector<pair<ll, ll>> vec(n);

    for(int i=0; i<n; i++){
        cin >> vec[i].first >> vec[i].second;
    }

    sort(vec.begin(), vec.end());

    for(int i=0; i<n; i++){
        exit.push(vec[i].second);

        while(exit.size() && exit.top() <= vec[i].first)
            exit.pop();

        ans = max(ans, (int)exit.size());
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