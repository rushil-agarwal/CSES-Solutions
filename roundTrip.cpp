#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, int par, vector<vector<int>> &adj, vector<int> &parent, vector<bool> &visited, int &start, int &end){
    visited[node] = true;
    parent[node] = par;

    for(auto it: adj[node]){
        if(it == par)
            continue;

        if(visited[it]){
            start = it;
            end = node;
            return true;
        }

        parent[it] = node;
        if(dfs(it, node, adj, parent, visited, start, end))
            return true;
    }

    return false;
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);

    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    int start = -1, end = -1;

    for(int i=0; i<n; i++){
        if(visited[i])
            continue;

        if(dfs(i, -1, adj, parent, visited, start, end)){
            break;
        }
    }

    if(start == -1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> path;
    path.push_back(start+1);
    
    while(end != start){
        path.push_back(end+1);
        end = parent[end];
    }

    path.push_back(start+1);

    reverse(path.begin(), path.end());

    cout << path.size() << endl;

    for(auto it: path)
        cout << it << " ";

        return 0;



}