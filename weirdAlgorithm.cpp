#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ll num; cin >> num;
    while(num != 1){
        cout << num << " ";
        if(num&1)
            num = num*3+1;
        else
            num/=2;
    }

    cout << num << endl;

    return 0;
}