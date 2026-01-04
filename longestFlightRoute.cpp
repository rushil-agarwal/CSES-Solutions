#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> inDegree(n, 0);

    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        u--; v--;

        adj[u].push_back(v);
        inDegree[v]++;
    }

    queue<int> q;
    vector<int> dp(n, INT_MIN), parent(n, -1);
    dp[0] = 1;
    parent[0] = 0;

    for(int i=0; i<n; i++){
        if(!inDegree[i])
            q.push(i);
    }

    while(q.size()){
        int node = q.front(); q.pop();

        for(auto it: adj[node]){
            inDegree[it]--;

            if(dp[node] != INT_MIN && dp[node] + 1 > dp[it]){
                dp[it] = dp[node] + 1;
                parent[it] = node;
            }

            if(inDegree[it] == 0){
                q.push(it);
            }
        }
    }

    if(parent[n-1] == -1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }


    vector<int> path;
    int curr = n-1;

    while(curr != parent[curr]){
        path.push_back(curr);
        curr = parent[curr];
    }

    path.push_back(0);

    reverse(path.begin(), path.end());

    cout << path.size() << endl;
    for(auto it: path)
        cout << it+1 << " ";


    return 0;
}