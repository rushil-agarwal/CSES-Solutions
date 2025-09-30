#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n; cin >> n;
    vector<ll> vec(n);
    for(int i=0; i<n; i++)
        cin >> vec[i];

    ll ans = 0;

    for(int i =1 ; i<n; i++){
        ans += max(1LL*0, vec[i-1]-vec[i]);
        vec[i] += max(1LL*0, vec[i-1]-vec[i]);
    }

    cout << ans << endl;

    return 0;
}