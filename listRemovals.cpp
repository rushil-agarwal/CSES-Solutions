#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

class fenwickTree{
    int n;
    vector<int> bit;

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

    int query(int idx){
        int sum=0;
        while(idx > 0){
            sum += bit[idx];
            idx -= idx&(-idx);
        }

        return sum;
    }

    int kth(int k){
        int idx=0;
        int stepSize=1;

        while(stepSize*2 <= n)
            stepSize*=2;

        for(; stepSize > 0; stepSize>>=1){
            int next = idx + stepSize;

            if(next <= n && bit[next] < k){
                k-=bit[next];
                idx = next;
            }
        }

        return idx+1;
    }
};

void solve(){
    int n; cin >> n;

    vector<ll> nums(n+1);
    fenwickTree fTree(n);
    

    for(int i=1; i<=n; i++){
        cin >> nums[i];
        fTree.update(i, 1);    
    }

    for(int i=0; i<n; i++){
        int k;  cin >> k;

        int idx = fTree.kth(k);
        cout << nums[idx] << " ";

        fTree.update(idx, -1);
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
