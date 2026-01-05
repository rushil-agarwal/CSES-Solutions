#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, power = 31; cin >> n >> q;
    vector<vector<int>> dp(n, vector<int> (power, 0));

    for(int i=0; i<n; i++){
        cin >> dp[i][0];
        dp[i][0]--; 
    }

    for(int pow = 1; pow<power; pow++){
        for(int node=0; node<n; node++){
            dp[node][pow] = dp[dp[node][pow-1]][pow-1];

        }
    }

    while(q--){
        int node, jumps; cin >> node >> jumps;
        node--;

        for(int i=0; i<power; i++){
            if(jumps & (1 << i))
                node = dp[node][i];
        }

        cout << node+1 << "\n";
    }

    return 0;


}