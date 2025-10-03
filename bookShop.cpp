#include<bits/stdc++.h>
using namespace std;
//
//int funct(int idx, int budget, vector<int> &price, vector<int> &pages, vector<vector<int>> &dp){
//    if(idx == pages.size())
//        return 0;
//
//    if(dp[idx][budget] != -1)
//        return dp[idx][budget];
//
//    int ans = 0;
//    //skip current book
//    ans = max(ans, funct(idx+1, budget, price, pages, dp));
//    //buy current book if can
//    if(budget >= price[idx])
//        ans = max(ans, pages[idx] + funct(idx+1, budget-price[idx], price, pages, dp));
//
//    return dp[idx][budget] = ans;
//
//
//}

int main(){
    int n, budget;
    cin >> n >> budget;
    vector<int> price(n), pages(n);

    for(int i=0; i<n; i++)
        cin >> price[i];

    for(int i =0; i<n; i++)
        cin >> pages[i];

    //vector<vector<int>> dp(n, vector<int> (budget+1, -1));
    //cout << funct(0, budget, price, pages, dp) << endl;
    vector<int> dp(budget+1, 0);

    for(int i=0; i<n; i++){
        for(int j = budget; j>=0;j--){
            if(j < price[i])
                continue;
            dp[j] = max(dp[j], pages[i]+dp[j-price[i]]);
        }
    }

    cout << dp[budget] << endl;

    return 0;
}