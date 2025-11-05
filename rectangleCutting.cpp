#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int ans = 0;

    vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i == j){
                dp[i][j] = 0;
                continue;
            }

            for(int h = 1; h<i; h++)
                dp[i][j] = min(dp[i][j], dp[h][j] + dp[i-h][j] + 1);

            for(int v = 1; v<j; v++)
                dp[i][j] = min(dp[i][j], dp[i][v] + dp[i][j-v] + 1);
        }
    }

    cout << dp[n][m] << endl;

    return 0;
    
}