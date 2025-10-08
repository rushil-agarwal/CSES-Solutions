#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<long long> weights(n);

    for(int i=0; i<n; i++)
        cin >> weights[i];

    long long ans = INT_MAX;

    for(int i=0; i<(1<<n); i++){
        long long pileA=0, pileB=0;

        for(int j=0; j<n; j++){
            if((i>>j)&1)
                pileA+=weights[j];
            else
                pileB+=weights[j];
        }

        ans = min(ans, abs(pileA - pileB));
    }
    cout << ans << endl;
    return 0;


}