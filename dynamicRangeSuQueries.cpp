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
        bit.resize(size+1, 0);
    }

    void update(int idx, ll change){
        while(idx <= n){
            bit[idx] += change;
            idx += (idx&(-idx));
        }
    }

    ll query(int idx){
        ll sum=0;
        while(idx > 0){
            sum += bit[idx];
            idx -= (idx&(-idx));
        }

        return sum;
    }
};

void solve(){
    int n, q; cin >> n >> q;

    vector<ll> nums(n);
    vector<tiii> queries(q);
    fenwickTree fTree(n);

    for(int i=0; i<n; i++){
        cin >> nums[i];
        fTree.update(i+1, nums[i]);
    }

    for(int i=0; i<q; i++){
        int type, left, right;
        cin >> type >> left >> right;

        queries[i] = {type, left, right};
    }

    for(auto &[type, a, b]: queries){
        if(type == 1){
            
            fTree.update(a, b-nums[a-1]);

            nums[a-1] = b;

        } else {
            cout << fTree.query(b) - fTree.query(a-1) << '\n'; 
        }
    }
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