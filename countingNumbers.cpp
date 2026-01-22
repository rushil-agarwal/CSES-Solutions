#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

ll dp[19][2][11][2];

ll funct(int idx, bool tight, int prev, bool leadingZero, string &num){
    if(idx == num.length())
        return 1;

    if(dp[idx][tight][prev+1][leadingZero] != -1)
        return dp[idx][tight][prev+1][leadingZero];

    int limit = (tight) ? 9 : (num[idx]-'0');

    ll ans = 0;

    for(int digit = 0; digit<= limit; digit++){
        if(!leadingZero && digit == prev)
            continue;

        bool newTight = (tight) ? true : (digit < limit);
        bool newLeading = (leadingZero && (digit == 0));
        int newPrev = (newLeading) ? -1 : digit;

        ans += funct(idx+1, newTight, newPrev, newLeading, num);
    }

    return dp[idx][tight][prev+1][leadingZero] = ans;

}

void solve(){
    ll a, b; cin >> a >> b;

    if(a > b)
        swap(a, b);

    string num1 = to_string(a-1);
    string num2 = to_string(b);

    memset(dp, -1, sizeof(dp));
    ll ans1 = funct(0, false, -1, true, num2);

    memset(dp, -1, sizeof(dp));
    ll ans2 = funct(0, false, -1, true, num1);

    cout << ans1 - ans2 << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
  //  cin >> t;
    while(t--)
        solve();

    return 0;
}