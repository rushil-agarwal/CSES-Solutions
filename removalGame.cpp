#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

ll funct(int first, int last, vector<ll> &nums, vector<vector<ll>> &dp){
    if(first > last)
        return 0;

    if(dp[first][last] != LLONG_MIN)
        return dp[first][last];

    ll ans = LLONG_MIN;

    ans = max(ans, nums[first] - funct(first+1, last, nums, dp));
    ans = max(ans, nums[last] - funct(first, last-1, nums, dp));
    
    return dp[first][last] = ans;
}

void solve(){
    int n; cin >> n;
    ll total =0;
    vector<ll> nums(n);

    for(int i=0; i<n; i++)
        cin >> nums[i], total += nums[i];

    vector<vector<ll>> dp(n, vector<ll> (n, LLONG_MIN));
    ll ans = funct(0, n-1, nums, dp);

    cout << (total+ans)/2 << '\n';

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