#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited){
    visited[node] = true;

    for(auto it: adj[node]){
        if(!visited[it])
            dfs(it, adj, visited);
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);
    vector<int> nodes;

    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i<n; i++){
        if(visited[i])
            continue;

        nodes.push_back(i);

        dfs(i, adj, visited);
    }

    cout << nodes.size() -1 << endl;
    for(int i=1; i<nodes.size(); i++){
        cout << nodes[0] +1 << " " << nodes[i]+1 << endl;
    }

    return 0;


}