#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

void solve(){
    ll n, m;
    cin >> n >> m;
    multiset<ll> tickets;

    for(int i=0; i<n; i++){
        ll temp; cin >> temp;
        tickets.insert(temp);
    }

    vector<ll> ans;

    while(m--){
        ll maxPrice; cin >> maxPrice;

        auto it = tickets.upper_bound(maxPrice);

        if(it == tickets.begin())
            ans.push_back(-1);
        else {
            it--;
            ans.push_back(*it);
            tickets.erase(it);
        }
    }

    for(auto it: ans)
        cout << it << " ";
    
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