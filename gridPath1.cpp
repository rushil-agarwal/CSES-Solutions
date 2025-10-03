#include<bits/stdc++.h>
#define mod (int)(1e9+7)
using namespace std;

int funct(int i, int j, int &n, vector<vector<char>> &vec, vector<vector<int>> &dp){
    if(i<0 || i>=n || j<0 || j>=n || vec[i][j] == '*')
        return 0;

    if(i == n-1 && j == n-1)
        return 1;


    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = 0;
    ans = (ans + funct(i+1, j, n, vec, dp))%mod;
    ans = (ans + funct(i, j+1, n, vec, dp))%mod;

    return dp[i][j] = ans;

}

int main(){
    int n; cin >> n;
    vector<vector<char>> vec(n, vector<char>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin >> vec[i][j];
    }

    if(vec[n-1][n-1] == '*'){
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    //cout << funct(0, 0, n, vec, dp) << endl;

    dp[n-1][n-1] = 1;

    for(int i = n-1; i>=0; i--){
        for(int j = n-1; j>=0; j--){
            if(vec[i][j] == '*')
                continue;
            if(i+1 < n)
                dp[i][j] = (dp[i][j] + dp[i+1][j])%mod;
            if(j+1<n)
                dp[i][j] = (dp[i][j] + dp[i][j+1])%mod;
        }
    }

    cout << dp[0][0] << endl;

    return 0;
}