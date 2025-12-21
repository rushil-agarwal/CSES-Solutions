#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<long long>> distance(n, vector<long long>(n, LLONG_MAX));

    for(int i=0; i<m; i++){
        long long u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;

        distance[u][v] = min(distance[u][v], w);
        distance[v][u] = min(distance[v][u], w);
    }

    vector<pair<int, int>> queries;

    for(int i=0; i<q; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;

        queries.push_back({u, v});

    }

    

    for(int k=0; k<n; k++){

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j)
                    distance[i][j] = 0;

                if(distance[i][k] != LLONG_MAX && distance[k][j] != LLONG_MAX)
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    for(auto &[u, v] : queries){
        cout << ((distance[u][v]  == LLONG_MAX) ? -1 : distance[u][v]) << endl;
    }

    return 0;
}