#include<bits/stdc++.h>
#define mod (int)(1e9+7)
using namespace std;

int main(){
    int t; cin >> t;
    vector<int> vec(t);
    int maxHeight = 0;
    for(int i=0; i<t; i++){
        cin >> vec[i];
        maxHeight = max(maxHeight, vec[i]);
    }

    vector<int> a(maxHeight+1), b(maxHeight+1);

    a[1] = 1; b[1] = 1;

    for(int i = 2; i<=maxHeight; i++){
        a[i] = (4LL*a[i-1] + 1LL*b[i-1])%mod;
        b[i] = (1LL*a[i-1] + 2LL*b[i-1])%mod;
    }

    for(auto &it: vec)
        cout << (a[it] + b[it])%mod << endl;


    return 0;
}