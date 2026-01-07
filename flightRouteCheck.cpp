#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj){
    visited[node] = true;

    for(auto it: adj[node]){
        if(!visited[it])
            dfs(it, visited, adj);
    }
}


void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n), invAdj(n);

    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        a--;
        b--;

        adj[a].push_back(b);
        invAdj[b].push_back(a);
    }

    //case 1: 1 to all
    vector<bool> visited(n, false);
    dfs(0, visited, adj);

    for(int i=0; i<n; i++){
        if(!visited[i]){
            cout << "NO" << endl;
            cout << 1 << " " << i+1 << endl;
            return;
        }
    }

    //case 2: all to 1
    vector<bool> vis(n, false);
    dfs(0, vis, invAdj);

    for(int i=0; i<n; i++){
        if(!vis[i]){
            cout << "NO" << endl;
            cout << i+1 << " " << 1 << endl;
            return;
        }
    }

    cout << "YES" << endl;

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