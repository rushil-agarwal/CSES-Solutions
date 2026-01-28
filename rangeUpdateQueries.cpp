#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

class fenwickTree{
    int n; 
    vector<ll> bit;
public:

    fenwickTree(int size){
        n = size;
        bit.resize(size+1, 0);
    }

    void update(int idx, int change){
        while(idx <= n){
            bit[idx] += change;
            idx += idx & (-idx);
        }
    }

    ll query(int idx){
        ll sum=0;
        while(idx > 0){
            sum += bit[idx];
            idx -= idx&(-idx);
        }

        return sum;
    }
};

void solve(){
    int n, q;
    cin >> n >> q;

    vector<ll> nums(n);

    for(int i=0; i<n; i++)
        cin >> nums[i];

    fenwickTree fTree(n);

    for(int i=0; i<q; i++){
        int type; cin >> type;

        if(type == 1){
            int left, right;
            ll change;
            cin >> left >> right >> change;

            fTree.update(left, change);
            fTree.update(right+1, -change);
        } else {
            int idx; cin >> idx;

            cout << nums[idx-1] + fTree.query(idx) << '\n';
        }
    }
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