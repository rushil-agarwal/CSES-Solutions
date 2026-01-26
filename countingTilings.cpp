#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

void generateNextMask(int n, int currMask, int newMask, int idx, vector<int> &nextMask){
    if( idx >= n){
        nextMask.push_back(newMask);
        return;
    }

    // current position filled so move to next
    if((1 << idx) & (currMask))
        generateNextMask(n, currMask, newMask, idx+1, nextMask);

    //place a 1x2 tile
    bool tile1x2 = (!((1<<idx) & currMask));

    if(tile1x2){
        generateNextMask(n, currMask, newMask | (1<<idx), idx+1, nextMask);
    }

    // plave 2x1 tile
    bool tile2x1 = ((idx+1 < n) && (!((1<<idx) & currMask)) && (!((1<<(idx+1)) & currMask)));

    if(tile2x1)
        generateNextMask(n, currMask | (1<<idx) | (1<<(idx+1)), newMask , idx+2, nextMask);
}

int funct(int n, int m, int idx, int mask, vector<vector<int>> &dp){
    if(idx == m){
        return (mask == 0);
    }

    if(dp[idx][mask] != -1)
        return dp[idx][mask];

    int ans = 0;
    vector<int> nextMask;

    generateNextMask(n, mask, 0, 0, nextMask);

    for(auto it: nextMask){
        ans = (ans + funct(n, m, idx+1, it, dp)) % mod;
    }

    return dp[idx][mask] = ans;
}

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<int>> dp(m+1, vector<int>((1<<n), -1));

    int ans = funct(n, m, 0, 0, dp);

    cout << ans << '\n';
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