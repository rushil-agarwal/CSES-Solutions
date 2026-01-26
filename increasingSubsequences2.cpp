#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

class fenwickTree{
    vector<ll> bit;
    int n;
public:
    fenwickTree(int size){
        n = size;
        bit.resize(n+1, 0);
    }

    void update(int idx, ll num){

        while(idx <= n){
            bit[idx] += num;

            idx += idx & (-idx);
        }
    }

    ll query(int idx){
        ll sum = 0;

        while(idx > 0){
            sum += bit[idx];
            idx -= idx & (-idx);
        }

        return sum;
    }
};

void solve(){
    int n; cin >> n;
    vector<ll> nums(n);
    map<ll, int> hash;

    for(int i=0; i<n; i++){
        cin >> nums[i];
        hash[nums[i]]++;
    }

    int idx = 1;
    for(auto &it: hash){
        it.second = idx;
        idx++;
    }

    for(auto &it: nums)
        it = hash[it];

    ll ans = 0;
    fenwickTree fw(n);
    for(auto it: nums){
        // subsequences till now
        int sub = (1+fw.query(it-1))%mod;

        ans = (ans + sub)%mod;

        // include these sub at index x, to be included later
        fw.update(it, sub);
    }

    cout << ans << '\n';
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