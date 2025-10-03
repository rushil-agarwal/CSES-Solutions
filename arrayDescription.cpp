#include<bits/stdc++.h>
#define mod (int)(1e9+7)
using namespace std;

int main(){
    int n, m; cin >> n >> m;

    vector<int> vec(n);
    for(int i=0; i<n; i++) cin >> vec[i];

    vector<vector<long long>> dp(n, vector<long long>(m+2, 0));

    for(int i=0; i<n; i++){
        if(i == 0){
            if(vec[i] == 0){
                for(int val=1; val<=m; val++)
                    dp[i][val]=1;
            } else {
                dp[i][vec[i]] = 1;
            }
        } else {
            if(vec[i] == 0){
                for(int val = 1; val<=m; val++)
                    dp[i][val] += (dp[i-1][val] + dp[i-1][val-1] + dp[i-1][val+1])%mod;
            } else {
                dp[i][vec[i]] = (dp[i-1][vec[i]] + dp[i-1][vec[i]-1] + dp[i-1][vec[i]+1])%mod;
            }
        }
    }

    long long ans = 0;
    for(auto it: dp[n-1])
        ans = (ans + it)%mod;

    cout << ans << endl;

    return 0;
}