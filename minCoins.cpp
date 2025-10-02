#include<bits/stdc++.h>
using namespace std;

int recursion(int idx, int currSum, vector<int> &coins, vector<vector<int>> &dp){
    if(currSum == 0)
        return 0;
    if(idx == coins.size() || currSum < 0)
        return 1e9;

    if(dp[idx][currSum] != -1)
        return dp[idx][currSum];

    if(coins[idx] > currSum)
        return dp[idx][currSum] = 1e9;

    // option 1: move to next coin
    int opt1 = recursion(idx+1, currSum, coins, dp);
    // option 2: take current coin and stay
    int opt2 = 1 + recursion(idx, currSum-coins[idx], coins, dp);

    return dp[idx][currSum] = min(opt1, opt2);
}

int main(){
    int n, x; cin >> n >> x;
    vector<int> coins(n);

    for(int i=0; i<n; i++)
        cin >> coins[i];

    //vector<vector<int>> dp(n, vector<int> (x+1, -1));
    vector<int> dp(x+1, 1e9);
    dp[0] = 0;

    for(int idx = n-1; idx>=0; idx--){
        for(int currSum = 0; currSum <=x; currSum++){
            if(currSum < coins[idx])
                continue;
            dp[currSum] = min(dp[currSum], dp[currSum - coins[idx]]+1);
        }
    }

    if(dp[x] == 1e9)
        cout << -1 << endl;
    else
        cout << dp[x] << endl;

//    int ans = recursion(0, x, coins, dp);
//
//    cout << ((ans == 1e9) ? -1 : ans ) << endl;

    return 0;
}