#include<bits/stdc++.h>
using namespace std;

int funct(int idx, int sum, vector<int> &coins, vector<vector<int>> &dp){
    if(sum == 0)
        return 1;

    if(idx == coins.size() || sum < 0)
        return 0;

    if(dp[idx][sum] != -1)
        return dp[idx][sum];

    bool possible = false;

    possible |= funct(idx+1, sum-coins[idx], coins, dp);
    possible |= funct(idx+1, sum, coins, dp);

    return dp[idx][sum] = possible ? 1 : 0;
}

int main(){
    int n; cin >> n;
    vector<int> coins(n);

    for(int i=0; i<n; i++)
        cin >> coins[i];


    int totalSum = accumulate(coins.begin(), coins.end(), 0);


    //vector<int> dp(totalSum+1, -1);
    vector<vector<int>> dp(n+1, vector<int>(totalSum+1, -1));
    int cnt = 0;
    for(int i = 1; i<= totalSum; i++){
        funct(0, i, coins, dp);
    }

    set<int> ans;
    
    for(int i=1; i<=totalSum; i++){
        for(int j = 0; j<n; j++){
            if(dp[j][i] == 1){
                ans.insert(i);
            }
        }
    }

    cout << ans.size() << endl;
    for(auto &it: ans)
        cout << it << " ";

    return 0;
}