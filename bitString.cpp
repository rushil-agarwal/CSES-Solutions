#include<bits/stdc++.h>
#define mod (int)(1e9+7)
#define ll long long
using namespace std;

ll calculate(int n){

    if(n == 1)
        return 2;

    return (n&1) ? (2*calculate(n-1))%mod : (calculate(n/2)*calculate(n/2))%mod;
}

int main(){

    int n; cin >> n;

    cout << calculate(n) << endl;

    return 0;
}