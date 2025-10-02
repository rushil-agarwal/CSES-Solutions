#include <bits/stdc++.h>
#define mod (int)(1e9+7)
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    vector<int> dp(target+1, 0);
    dp[0] = 1;

    for(int t = 1; t<=target; t++){
        for(int i=0; i<n; i++){
            if(t - coins[i] >= 0)
                dp[t] = (dp[t] + dp[t-coins[i]])%mod;
        }
    }

    cout << dp[target] << endl;

    return 0;
}
