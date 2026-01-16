#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

void solve(){
    ll x, n; cin >> x >> n;

    vector<ll> posts(n);

    for(int i=0; i<n; i++)
        cin >> posts[i];

    
    set<pair<ll, ll>> segments;
    multiset<ll> lengths;

    segments.insert({0, x});
    lengths.insert(x);

    for(auto &post: posts){
        auto it = segments.upper_bound({post, 0});
        it--;

        int left = it->first, right = it->second;

        segments.erase(it);
        lengths.erase(lengths.find(right - left));

        segments.insert({left, post});
        lengths.insert({post - left});

        segments.insert({post, right});
        lengths.insert({right - post});

        cout << *lengths.rbegin() << ' ';
    }
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