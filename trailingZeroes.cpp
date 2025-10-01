#include<bits/stdc++.h>
#define ll long long
using namespace std;

int factors(ll n){
    int fives = 0;

    while(n%5 == 0){
        fives++;
        n/=5;
    }

    return fives;
}

int main(){
    ll n; cin >> n;
    int fives = 0;

    for(int i=5; i<=n; i+=5){
        fives += factors(i);
    }

    cout << fives << endl;
    return 0;
}