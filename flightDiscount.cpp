#include<bits/stdc++.h>
#define tp tuple<long long, int, bool>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int, long long>>> adj(n);

    for(int i=0; i<m; i++){
        int u, v; long long w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back({v, w});
    }

    vector<vector<long long>> distance(n, vector<long long>(2, LLONG_MAX));
    priority_queue<tp, vector<tp>, greater<tp>> pq;

    distance[0][0] = 0;
    pq.push({0, 0, false});

    while(pq.size()){
        auto [dist, node, used] = pq.top(); pq.pop();

        if(dist > distance[node][used])
            continue;

        for(auto &[it, wt]: adj[node]){

            // without discount
            if(dist + wt < distance[it][used]){
                distance[it][used] = dist+wt;
                pq.push({dist+wt, it, used});
            }

            //if available, add discounted path too
            if(!used){
                if(dist + wt/2 < distance[it][1]){
                    distance[it][1] = dist+wt/2;

                    pq.push({distance[it][1], it, true});
                }
            }
        
        }
    }

    cout << min(distance[n-1][0], distance[n-1][1]) << endl;

    

    return 0;

}