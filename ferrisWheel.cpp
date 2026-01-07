#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

void solve(){
    int n;
    ll limit;
    cin >> n >> limit;

    vector<ll> weights(n);

    for(int i=0; i<n; i++)
        cin >> weights[i];

    sort(weights.begin(), weights.end());

    int ans = 0, left = 0, right = n-1;

    while(left <= right){
        if(left == right){
            ans++;
            break;
        } else if(weights[left] + weights[right] <= limit){
            left++;
            right--;
            ans++;
        } else {
            right--;
            ans++;
        }
    }
    cout << ans << endl;
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