#include<bits/stdc++.h>
using namespace std;

int start = -1, ended = -1;

bool dfs(int node, vector<vector<int>> &adj, vector<int> &parent, vector<int> &state){
    state[node] = 1;
    for(auto &it: adj[node]){
        if(state[it] == 0){
            parent[it] = node;

            if(dfs(it, adj, parent, state)){
                return true;
            }


        } else if(state[it]== 1){
            start = it;
            ended = node;

            return true;
        }
    }

    state[node] = 2;
    return false;
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);

    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        u--; 
        v--;
        adj[u].push_back(v);
    }

    vector<int> parent(n, -1);
    vector<int> state(n, 0);

    for(int i=0; i<n; i++){
        if(state[i] != 0)
            continue;

        if(dfs(i, adj, parent, state)){
            vector<int> cycle;
            cycle.push_back(start);

            while(ended != start)
                cycle.push_back(ended), ended = parent[ended];

            cycle.push_back(start);
            reverse(cycle.begin(), cycle.end());

            cout << cycle.size() << endl;
            for(auto &it: cycle)
                cout << it+1 << " ";

            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}