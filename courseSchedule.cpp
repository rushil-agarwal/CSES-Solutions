#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> inDegree(n, 0);
    
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;

        adj[u].push_back(v);
        inDegree[v]++;
    }

    vector<int> ans;
    queue<int>q;

    for(int i=0; i<n; i++){
        if(inDegree[i] == 0)
            q.push(i);
    }

    while(q.size()){
        int node = q.front(); q.pop();
        ans.push_back(node);

        for(auto it: adj[node]){
            inDegree[it]--;

            if(inDegree[it] == 0)
                q.push(it);
        }
    }

    if((int)ans.size() != n){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for(auto it: ans)
        cout << it+1 << " ";

    return 0;

    


}