#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

void revDfs(int node, vector<bool> &visited, vector<vector<int>> &adj, vector<int> &comp){
    visited[node] = true;
    comp.push_back(node);

    for(auto it: adj[node]){
        if(!visited[it])
            revDfs(it, visited, adj, comp);
    }
}


void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj, stack<int> &stk){
    visited[node] = true;

    for(auto it: adj[node]){
        if(!visited[it])
            dfs(it, visited, adj, stk);
    
        }

    stk.push(node);
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n), invAdj(n);

    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        a--; b--;

        adj[a].push_back(b);
        invAdj[b].push_back(a);
    }

    vector<bool> visited(n, false);
    int cnt=1;
    vector<int> kingdom(n, 0);
    stack<int> stk;

    for(int i=0; i<n; i++){
        if(!visited[i])
            dfs(i, visited, adj, stk);
    }

    
        vector<bool> vis(n, false);

    while(stk.size()){
        int node = stk.top(); stk.pop();

        if(vis[node])
            continue;

        vector<int> comp;

        revDfs(node, vis, invAdj, comp);
        for(auto it: comp)
            kingdom[it] = cnt;

        cnt++;
    }


    cout << cnt-1 << endl;
    for(auto it: kingdom)
        cout << it << " ";

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    while(t--)
        solve();

    return 0;
}