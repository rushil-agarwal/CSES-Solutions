#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){

    int n; cin >> n;
    vector<int> vec(n);
    int temp1 = 0, temp2 = n;
    for(int i=0; i<n-1; i++){
        int x; cin >> x;
        temp1 = temp1^x;
        temp2 = temp2^(i+1);
    }

    cout << (temp1 ^ temp2) << endl;
    
    return 0;
}