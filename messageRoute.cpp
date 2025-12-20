#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    
    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(n, -1);
    queue<int> q;

    parent[0] = 0;
    q.push(0);

    while(q.size()){
        int node = q.front();
        q.pop();

        for(auto it: adj[node]){
            if(parent[it] != -1)
                continue;

            parent[it] = node;
            q.push(it);
        }
    }

    if(parent[n-1] == -1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> path;
    int curr = n-1;

    while(curr != 0){
        path.push_back(curr+1);
        curr = parent[curr];
    }

    path.push_back(1);

    reverse(path.begin(), path.end());

    cout << path.size() << endl;
    for(auto it: path)
        cout << it << " ";

    return 0;
}