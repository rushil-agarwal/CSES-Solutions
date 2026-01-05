#include<bits/stdc++.h>
#define mod (int)(1e9+7)
using namespace std;

void dfs(int node, vector<bool> &canTake, vector<vector<pair<int, int>>> &adj){
    canTake[node] = true;

    for(auto &[it, w]: adj[node]){
        if(!canTake[it])
            dfs(it, canTake, adj);
    }
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int, long long>>> adj(n);
    vector<tuple<long long, int, int, int>> dp(n, {LLONG_MAX, 0, 0, 0});
    // distance, number of ways, min flights, max flights

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dp[0] = {0, 1, 0, 0};
    pq.push({0, 0});

    for(int i=0; i<m; i++){
        int u, v;
        long long w; cin >> u >> v >> w;
        u--; v--;

        adj[u].push_back({v, w});
    }

    while(pq.size()){
        auto [w, node] = pq.top(); pq.pop();
        
        if(get<0>(dp[node]) < w)
            continue;

        for(auto &[it, w]: adj[node]){
            auto &[dist, ways, minF, maxF] = dp[it];
            auto &[currDist, currWays, currMinF, currMaxF] = dp[node];

            if(w + currDist < dist){
                dist = w + currDist;
                ways = currWays;
                minF = currMinF + 1;
                maxF = currMaxF + 1;
                pq.push({dist, it});
            
            } else if(w + currDist == dist){
                ways = (ways + currWays)%mod;
                minF = min(minF, currMinF + 1);
                maxF = max(maxF, currMaxF + 1);
            }

            
        }
    }


    cout << get<0>(dp[n-1]) << " " << get<1>(dp[n-1]) << " " << get<2>(dp[n-1]) << " " << get<3>(dp[n-1]) << endl;

    return 0;
}