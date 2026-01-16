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

    int left=0, right=0;
    ll ans=0;
    unordered_set<ll> visited;

    while(right < n){
        while(visited.count(nums[right])){
            visited.erase(nums[left]);
            left++;
        }

        visited.insert(nums[right]);

        ans += (right-left+1);
        right++;
    }

    cout << ans << endl;
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