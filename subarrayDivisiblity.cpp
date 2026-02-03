#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

void solve(){
    int n; cin >> n;
    vector<ll> nums(n);

    for(int i=0; i<n; i++)
        cin >> nums[i];

    ll sum=0;
    map<int, int> freq;

    freq[0] = 1;

    for(int i=0; i<n; i++){
        sum += nums[i];

        int rem = (sum%n + n)%n;

        freq[rem]++;
    }

    ll cnt=0;

    for(auto it: freq){
        ll pairs = it.second;

        cnt += (1LL*pairs*(pairs-1))/2;
    }

    cout << cnt << '\n';

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
   // cin >> t;
    while(t--)
        solve();

    return 0;
}