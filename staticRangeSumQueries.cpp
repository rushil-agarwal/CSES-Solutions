#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;



void solve(){
    int n, q; cin >> n >> q;
    vector<ll> nums(n);
    
    for(int i=0; i<n; i++)
        cin >> nums[i];

    vector<pii> queries(q);

    for(int i=0; i<q; i++){
        int left, right; cin >> left >> right;
        left--;
        right--;
        queries[i] = {left, right};
    }

    vector<ll> prefix(n+1, 0);

    for(int i=0; i<n; i++)
        prefix[i+1] = prefix[i] + nums[i];

    for(auto &[left, right]: queries){
        cout << prefix[right+1] - prefix[left] << '\n';
    }


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