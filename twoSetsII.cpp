#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;


ll funct(int curr, int num, int n, int target, vector<vector<ll>> &dp){
    if(curr > target)
        return 0;
    if(num > n)
        return (curr == target);

    if(dp[curr][num] != -1)
        return dp[curr][num];

    ll ans =0;

    ans = (ans + funct(curr, num+1, n, target, dp))%mod;
    
    ans =  (ans + funct(curr+num, num+1, n, target, dp))%mod;

    return dp[curr][num] = ans;
}

void solve(){
    int n; cin >> n;

    int total = n*(n+1)/2;

    if(total&1){
        cout << "0\n";
        return;
    }

    vector<vector<ll>> dp(total/2+1, vector<ll>(n+1, -1));

    ll ans = funct(0, 1, n, total/2, dp);
    ll inv2 = (mod+1)/2;

    cout << (1LL*inv2*ans)%mod << '\n';
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