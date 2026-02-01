#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<ll, ll, int>
#define mod (int)(1e9+7)
using namespace std;


void solve(){
    int n; cin >> n;
    vector<tiii> vec(n);

    for(int i=0; i<n; i++){
        ll a, b; cin >> a >> b;
        vec[i] = {a, b, i};
    }

    int used=0;
    vector<ll> guests(n+1, -1);
    set<pair<ll, int>> rooms;

    sort(vec.begin(), vec.end());

    for(auto &[enter, leave, id]: vec){

        auto it = rooms.begin();

        if(rooms.empty() || it->first >= enter){
            rooms.insert({leave, used});
            guests[id] = used;
            used++;
        } else {
            int roomId = it->second;
            rooms.erase(it);
            guests[id] = roomId;
            rooms.insert({leave, roomId});

        }

    }

    cout << used << "\n";
    for(int i=0; i<n; i++)
        cout << guests[i]+1 << " ";

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