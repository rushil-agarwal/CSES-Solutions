#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> nums(n);

    for(int i=0; i<n; i++)
        cin >> nums[i];

    int left=0, right=0, ans = 0;
    map<int, int> hash;

    while(right < n){
        hash[nums[right]]++;

        while(hash[nums[right]] > 1){
            hash[nums[left]]--;

            if(hash[nums[left]] == 0)
                hash.erase(nums[left]);
            left++;
        }

        ans = max(ans, (int)hash.size());
        right++;
    }

    cout << ans << '\n';
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