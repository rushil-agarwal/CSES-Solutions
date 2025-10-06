#include<bits/stdc++.h>
using namespace std;

int funct(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
    if(i == s1.length() && j == s2.length())
        return 0;

    if(i == s1.length() || j == s2.length())
        return abs((int)s1.length() - i) + abs((int)s2.length() - j);


    if(dp[i][j] != -1)
        return dp[i][j];

    //case 1: letters are same, no operation needed
    if(s1[i] == s2[j])
        return funct(i+1, j+1, s1, s2, dp);

    //case 2: not same, ned to process
    int ans = 1e9;

    //option1 :replace and add
    ans = min(ans, 1+funct(i+1, j+1, s1, s2, dp));

    //option2: remove character from s1;
    ans = min(ans, 1+funct(i+1, j, s1, s2, dp));

    //remove character from s2;
    ans = min(ans, 1+funct(i, j+1, s1, s2, dp));

    return dp[i][j] = ans;




}

int main(){
    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int>> dp(s1.length(), vector<int> (s2.length(), -1));

    cout << funct(0, 0, s1, s2, dp) << endl;

    return 0;
}