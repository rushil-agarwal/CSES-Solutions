#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tlll tuple<ll, ll, ll>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

bool comp(tlll &a, tlll &b){
    return get<0>(a) < get<0>(b);
}

int search(vector<tlll> &projects, int left){
    int endTime = get<1>(projects[left]);
    int right = projects.size()-1;
    int idx = projects.size();
    while(left <= right){
        int mid = (left+right)/2;

        if(get<0>(projects[mid]) > endTime){
            idx = mid;
            right = mid-1;
        } else
            left = mid+1;
    }

    return idx;
}

ll funct(int idx, vector<tlll> &projects, vector<ll> &dp){
    if(idx == (int)projects.size())
        return 0;

    if(dp[idx] != -1)
        return dp[idx];

    ll ans = 0;

    // take current project
    int next = search(projects, idx);
    ans = max(ans, get<2>(projects[idx]) + funct(next, projects, dp));
    // skip
    ans = max(ans, funct(idx+1, projects, dp));

    return dp[idx] = ans;

}

void solve(){
    int n; cin >> n;
    vector<tlll> projects(n);
    vector<ll> dp(n, -1);

    for(int i=0; i<n; i++){
        ll start, end, money;
        cin >> start >> end >> money;
        projects[i] = {start, end, money};
    }

    sort(projects.begin(), projects.end(), comp);

    ll ans = funct(0, projects, dp);

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