#include<bits/stdc++.h>
#define mod (int)(1e9+7)
using namespace std;

int recursion(int currSum, int &target, vector<int> &dp){
    if(currSum > target)
        return 0;

    if(currSum == target)
        return 1;

    if(dp[currSum] != -1)
        return dp[currSum];

    int ans = 0;
    for(int i=1; i<=6; i++)
        ans = (ans + recursion(currSum+i, target, dp))%mod;

    return dp[currSum] = (ans)%mod;
}

int main(){
    int n; cin >> n;
    vector<int> dp(n+1, -1);

    cout << recursion(0, n, dp) << endl;

    return 0;
}
