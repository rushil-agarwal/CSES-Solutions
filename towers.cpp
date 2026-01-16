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

    multiset<ll> stacks;

    for(auto &num: nums){
        auto it = stacks.upper_bound(num);

        if(it == stacks.end())
            stacks.insert(num);
        else {
            stacks.erase(it);
            stacks.insert(num);
        }
    }

    cout << stacks.size() << '\n';
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