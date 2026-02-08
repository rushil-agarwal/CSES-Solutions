#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<int> nums(n+1), pos(n+1);

    for(int i=1; i<=n; i++){
        cin >> nums[i];
        pos[nums[i]] = i;
    }

    auto problem = [&](int num){
        if(num < 1 || num >= n )
            return 0;
        return (int)(pos[num+1] < pos[num]);
    };

    int cnt=1;
    for(int i=1; i<n; i++)
        cnt += (pos[i+1] < pos[i]);

    while(m--){
        int i, j;cin >> i >> j;

        int x = nums[i], y = nums[j];

        set<int> s = {x-1, x, y-1, y};

        for(auto it: s)
            cnt -= problem(it);

        swap(nums[i], nums[j]);

        pos[x] = j;
        pos[y] = i;

        for(auto it: s)
            cnt += problem(it);
            
        cout << cnt << '\n';
    }
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