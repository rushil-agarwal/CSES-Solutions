#include<bits/stdc++.h>
using namespace std;


bool solve(){
    long long a, b;
    cin >> a >> b;
    if((a+b)%3 != 0)
        return false;

    return (max(a, b) <= 2*min(a, b));
}

int main(){
    int t ;cin >> t;
    while(t--){
        if(solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}