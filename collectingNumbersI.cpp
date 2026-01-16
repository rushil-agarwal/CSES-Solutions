#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> vec(n), index(n+1);

    for(int i=0; i<n; i++){
        cin >> vec[i];
        index[vec[i]] = i;
    }

    int ans = 1;

    for(int i=1; i<n; i++){
        ans+=(index[i+1] < index[i]);
    }

    cout << ans << endl;

    
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