#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>

#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

int funct(int idx, vector<int> &dp, vector<ll> &nums){
    if(dp[idx] != -1)
        return dp[idx];

    int ans = 0;
    for(int i=0; i<idx; i++){
        if(nums[i] < nums[idx])
            ans = max(ans, funct(i, dp, nums) + 1);
    }

    return dp[idx] = ans;
}

void solve(){
    int n; cin >> n;
    vector<ll> nums(n);

    for(int i=0; i<n; i++)
        cin >> nums[i];

    vector<ll> dp;
 
    for(int i=0; i<n; i++){
        int idx = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();

        if(idx == dp.size())
            dp.push_back(nums[i]);
        else  
            dp[idx] = nums[i];
    }

    cout << dp.size() << '\n';
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