#include<bits/stdc++.h>
#define ll long long
using namespace std;

void yGreater(ll x, ll y){
    ll ans = (y-1)*(y-1);

    if(y&1){
        ans += x;
    } else {
        ans += 2*y-x;
    }

    cout << ans << endl;
}

void xGreater(ll x, ll y){
    ll ans = (x-1)*(x-1);
    if(x&1){
        ans += 2*x-y;
    } else
        ans += y;

    cout << ans << endl;

}



void solve(){
    ll x, y;
    cin >> y >> x;

    if(y > x)
        yGreater(x, y);
    else
        xGreater(x, y);
}

int main(){
    int t; cin >> t;
    while(t--)
        solve();

    return 0;
}