#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int, long long>>> adj(n);

    for(int i=0; i<m; i++){
        long long u, v, w; cin >> u >> v >> w;
        u--;v--;
        adj[u].push_back({v, w});
    }

    vector<long long> distance(n, LLONG_MAX);
    distance[0] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    pq.push({0, 0});
    //dist, node

    while(pq.size()){
        auto [dist, node] = pq.top(); pq.pop();

        if(dist > distance[node])
            continue;

        for(auto [it, cost] : adj[node]){
            if(distance[node] + cost < distance[it]){
                distance[it] = distance[node] + cost;
                pq.push({distance[it], it});
            }
        }
    }

    for(auto it: distance)
        cout << it << " ";
    
        return 0;

}