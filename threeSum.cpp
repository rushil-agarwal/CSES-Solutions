#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

pair<int, int> twoSum(vector<ll> &nums, vector<bool> &valid, ll x, int n){
    unordered_map<int, int> hash;

    for(int i=0; i<n; i++){
        if(!valid[i])
            continue;
        ll required = x - nums[i];

        if(hash.find(required) != hash.end()){
            return {i, hash[required]};
        }

        hash[nums[i]] = i;
    }

    return {-1, -1};
}

void solve(){
    int n;
    ll x; 
    cin >> n >> x;

    vector<pair<ll, int>> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i].first;
        nums[i].second = i;
    }

    sort(nums.begin(), nums.end());

    for(int i=0; i<n; i++){
        if(i!=0 && nums[i] == nums[i-1])
            continue;

        int left = i+1, right = n-1;

        while(left < right){
            int sum = nums[i].first + nums[left].first + nums[right].first;

            if(sum == x){
                cout << nums[i].second + 1 << " " << nums[left].second+1 << " " << nums[right].second+1;
                return;
            } else if(sum < x){
                left++;
            } else if(sum > x){
                right--;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
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