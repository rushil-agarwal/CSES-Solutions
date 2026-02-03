#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

bool comp(pll &a, pll &b){
    if(a.second == b.second)
        return a.first < b.first;

    return a.second < b.second;
}

void solve(){
    int n, k; cin >> n >> k;
    int cnt=0;
    vector<pll> movies(n);

    for(int i=0; i<n; i++)
        cin >> movies[i].first >> movies[i].second;

    sort(movies.begin(), movies.end(), comp);

    multiset<ll> store;

    for(auto [begin, end]: movies){
        auto it = store.upper_bound(begin);

        if(it != store.begin()){
            it--;
            store.erase(it);
            store.insert(end);
            cnt++;
        } else if(store.size() < k){
            store.insert(end);
            cnt++;
        }
    }

    cout << cnt << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
  //  cin >> t;
    while(t--)
        solve();

    return 0;
}