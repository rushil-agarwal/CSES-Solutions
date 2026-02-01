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

    stack<int> stk;

    vector<int> ans(n, 0);

    for(int i=0; i<n; i++){
        while(stk.size() && nums[stk.top()] >= nums[i])
            stk.pop();

        if(!stk.empty()){
            ans[i] = stk.top()+1;
        }

        stk.push(i);
    }

    for(auto it: ans)
        cout << it << " ";

    
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