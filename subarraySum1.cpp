#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

void solve(){
    int n;
    ll x;
    cin >> n >> x;

    vector<ll> nums(n);

    for(int i=0; i<n; i++)
        cin >> nums[i];

    int left=0, right=0;
    ll curr=0, ans=0;;

    while(right < n){
        curr += nums[right];

        while(left <= right && curr > x){
            curr -= nums[left];
            left++;
        }

        ans += (curr == x);
        right++;
    }

    cout << ans << '\n';
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