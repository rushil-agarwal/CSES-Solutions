#include<bits/stdc++.h>
#define mod (int)(1e9+7)
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> inDegree(n, 0), dp(n, 0);
    queue<int> q;

    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        u--; v--;

        adj[u].push_back(v);
        inDegree[v]++;
    }

    for(int i=0; i<n; i++){
        if(!inDegree[i])
            q.push(i);
    }

    dp[0] = 1;

    while(q.size()){
        int node = q.front(); q.pop();

        for(auto it: adj[node]){
            inDegree[it]--;

            dp[it] = (dp[it] + dp[node])%mod;

            if(!inDegree[it])
                q.push(it);
        }
    }

    cout << dp[n-1] << endl;

    return 0;   
}