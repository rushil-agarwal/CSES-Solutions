#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

bool comp(pii &a, pii&b){
    return a.second < b.second;
}

void solve(){
    int n; cin >> n;
    vector<pii> vec(n);

    for(int i=0; i<n; i++)
        cin >> vec[i].first >> vec[i].second;

    sort(vec.begin(), vec.end(), comp);
    int ans = 1, endTime = vec[0].second;

    for(int i=1; i<n; i++){
        if(vec[i].first >= endTime){
            ans++;
            endTime = vec[i].second;
        }
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