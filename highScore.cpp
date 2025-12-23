#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<vector<long long>> edges(m, vector<long long>(3));

    for(int i=0; i<m; i++){
        // int u, v, w; cin >> u >> v >> w;

        // u--; v--;
  
        // adj[u].push_back({v, -w});
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        edges[i][0]--;
        edges[i][1]--;
        edges[i][2] = -edges[i][2];
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    vector<long long> distance(n, LLONG_MAX);
    distance[0] = 0;

    for(int i=0; i<n-1; i++){
        for(auto &e: edges){
            int u = e[0], v = e[1], w = e[2];

            if(distance[u] != LLONG_MAX && distance[u] + w < distance[v])
                distance[v] = distance[u] + w;
        }
    }

    vector<bool> visited(n, false);
    vector<int> bad;

    for(auto &e: edges){
        int u = e[0], v = e[1], w = e[2];

        if(distance[u] != LLONG_MAX && distance[u] + w < distance[v]){
            bad.push_back(v);
        }
    }

    queue<int> q;
    for(auto &x: bad){
        q.push(x);
        visited[x] = true;
    }

    while(q.size()){
        int node = q.front(); q.pop();

        for(auto &it: adj[node]){
            if(!visited[it]){
                visited[it] = true;
                q.push(it);
            }
        }
    }

    if(visited[n-1])
        cout << -1 << endl;
    else   
        cout << -distance[n-1] << endl;

    return 0;
}