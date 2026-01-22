#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

void solve(){
    int n; cin >> n;
    ll limit; cin >> limit;

    vector<pii> dp(1<<n);
    vector<ll> weights(n);

    for(int i=0; i<n; i++)
        cin >> weights[i];

    
    dp[0] = {1, 0};

    for(int mask=1; mask < (1<<n); mask++){
        dp[mask] = {n+1, 0};

        for(int person=0; person<n; person++){
            if(mask & (1<<person)){
                int prevMask = mask ^ (1 << person);

                auto lastRide = dp[prevMask];

                if(lastRide.second + weights[person] <= limit)
                    lastRide.second += weights[person];
                else{
                    lastRide.first++;
                    lastRide.second = weights[person];
                }
                
                dp[mask] = min(dp[mask], lastRide);
            }
        }
    }

    cout << dp[(1<<n) - 1].first << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
 //   cin >> t;
    while(t--)
        solve();

    return 0;
}