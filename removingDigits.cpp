#include<bits/stdc++.h>
using namespace std;

int funct(int n, vector<int> &dp){
    if(n==0)
        return 0;

    if(dp[n] != -1)
        return dp[n];

    int temp = n;
    int ans = 1e9;
    while(temp){
        if(n - temp%10 != n)
            ans = min(ans, 1+funct(n-temp%10, dp));
        temp/=10;
    }

    return dp[n] = ans;
}

int main(){
    int n; cin >> n;
    vector<int> dp(n+1, 1e9);
    //cout << funct(n, dp) << endl;

    dp[0] = 0;

    for(int i = 1; i<=n; i++){
        int temp = i;
        while(temp){
            if(i - temp%10 != i)
                dp[i] = min(dp[i], 1+dp[i-temp%10]);
            temp/=10;
        }
    }
    cout << dp[n] << endl;
    return 0;
}