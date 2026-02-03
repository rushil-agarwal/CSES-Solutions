#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

bool check(vector<ll> &nums, int k, ll mid){
    int count=1;
    ll curr = 0;

    for(auto it: nums){
        if(it > mid)
            return false;

        if(curr + it > mid){
            count++;
            curr = it;

            if(count > k)
                return false;
        } else {
            curr += it;
        }
    }

    return (count <= k);
}

void solve(){
    int n, k; cin >> n >> k;
    vector<ll> nums(n);

    for(int i=0; i<n; i++)
        cin >> nums[i];

    ll left=0, right = accumulate(nums.begin(), nums.end(), 0LL);
    ll ans = right;

    while(left <= right){
        ll mid = (left+right)/2;

        if(check(nums, k, mid)){
            ans = mid;
            right = mid-1;
        } else 
            left = mid+1;
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    
    
    //cin >> t;
    while(t--)
        solve();

    return 0;
}