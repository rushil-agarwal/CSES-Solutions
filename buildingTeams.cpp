#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, int color, vector<vector<int>> &adj, vector<int> &group){
    
    group[node] = color;

    for(auto it: adj[node]){
        if(group[it] == -1){
            if(!dfs(it, 1-color, adj, group))
                return false;
        } else if(group[it] == color)
            return false;
    }

    return true;
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

    vector<int> group(n, -1);

    for(int i=0; i<n; i++){
        if(group[i] != -1)
            continue;

        if(!dfs(i, 0, adj, group)){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    for(auto it: group)
        cout << it + 1 << " ";

    return 0;
}
