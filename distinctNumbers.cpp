#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

void solve(){
    int n; cin >> n;
    set<ll> store;

    for(int i=0; i<n; i++){
        ll temp; cin >> temp;
        store.insert(temp);
    }

    cout << store.size() << endl;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    while(t--)
        solve();

    return 0;
}