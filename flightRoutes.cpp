#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<pair<int, long long>>> adj(n);
    vector<int> visited(n, 0);

    for(int i=0; i<m; i++){
        int u, v; long long w;
        cin >> u >> v >> w;
        u--;
        v--;

        adj[u].push_back({v, w});
    }
    
    vector<long long> ans;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    // cost, node

    q.push({0, 0});
    //unordered_map<int, long long> visited;

    while(q.size() && visited[n-1] < k){
        auto [cost, node] = q.top(); q.pop();
        visited[node]++;

        if(visited[node] > k)
            continue;

        if(node == n-1){
            ans.push_back(cost);
        }

        for(auto &[it, w]: adj[node]){
            q.push({cost+w,it});
        }
    }

 //   sort(ans.begin(), ans.end());

    for(auto &it: ans)
        cout << it << " ";

    return 0;
}