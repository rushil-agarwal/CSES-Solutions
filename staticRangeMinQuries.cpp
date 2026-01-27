#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

void builtSt(vector<vector<ll>> &sparseTable, vector<ll> &nums, int n){
    for(int i=0; i<n; i++)
        sparseTable[0][i] = nums[i];

    for(int level = 1; level<20; level++){
        int ahead = 1 << (level-1);

        for(int i=0; i+ahead <n; i++)
            sparseTable[level][i] =min(sparseTable[level-1][i], sparseTable[level-1][i+ahead]);
    }
}

ll minNum(vector<vector<ll>> &sparseTable, int left, int right){
    int len = right-left+1;
    int pow2 = log2(len);

    return min(sparseTable[pow2][left], sparseTable[pow2][right - (1<<pow2) + 1]);
}

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

    vector<vector<ll>> sparseTable(20, vector<ll>(n));

    builtSt(sparseTable, nums, n);

    for(auto &[left, right]: queries){

        cout << minNum(sparseTable, left, right) << '\n';
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
 //   cin >> t;
    while(t--)
        solve();

    return 0;
}