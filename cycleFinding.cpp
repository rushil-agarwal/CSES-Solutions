#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    vector<tuple<int, int, long long>> edges;

    for(int i=0; i<m; i++){

        int u, v;
        long long w;
        cin >> u >> v >> w;
        u--; v--;
        edges.push_back({u, v, w});
        adj[u].push_back({v, w});
    }

    vector<long long> dist(n, 0);
    vector<int> parent(n, -1);


    for(int i=0; i<n-1; i++){
        for(auto &[u, v, w]: edges){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    int node = -1;

    for(auto &[u, v, w]: edges){
        if(dist[u] + w < dist[v]){
            dist[v] = dist[u] + w;
            parent[v] = u;
            node = v;
        }
    }

    if(node == -1){
        cout << "NO" << endl;
        return 0;
    }

    for(int i=0; i<n; i++)
        node = parent[node];

   // cout << "NODE: " << node << endl;

    vector<int> path;
    int curr = node;
    do{
        path.push_back(curr);
        curr = parent[curr];
    } while(curr != node);

    path.push_back(node);

    reverse(path.begin(), path.end());

    cout << "YES" << endl;

    for(auto it: path)
        cout << it+1 << " ";

    return 0;


}