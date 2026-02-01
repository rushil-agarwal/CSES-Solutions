#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

struct range{
    ll left, right, idx;
};

bool comp(range &a, range &b){
    if(a.left == b.left){
        return a.right > b.right;
    } 
    return a.left < b.left;
}

void solve(){
    int n; cin >> n;
    vector<range> ranges(n);

    for(int i=0; i<n; i++){
        cin >> ranges[i].left >> ranges[i].right;
        ranges[i].idx = i;
    }

    sort(ranges.begin(), ranges.end(), comp);

    vector<bool> containes(n, false), contained(n, false);

    // contained
    ll maxR = 0;
    for(int i=0; i<n; i++){
        if(maxR >= ranges[i].right)
            contained[ranges[i].idx] = true;

        maxR = max(maxR, ranges[i].right);
    }

    // containes
    ll minR = LLONG_MAX;
    for(int i = n-1; i>=0; i--){
        if(minR <= ranges[i].right)
            containes[ranges[i].idx] = true;

        minR = min(minR, ranges[i].right);
    }

    for(auto it: containes)
        cout << it << " ";
    cout << '\n';

    for(auto it: contained)
        cout << it << " ";
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