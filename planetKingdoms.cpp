#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj, vector<bool> &fixed){
    visited[node] = true;

    for(auto it: adj[node]){
        if(!visited[it] && !fixed[it])
            dfs(it, visited, adj, fixed);
    }
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

    for(int i=0; i<n; i++){
        if(visited[i])
            continue;

        vector<bool> vis1(n, false), vis2(n, false);

        dfs(i, vis1, adj, visited);
        dfs(i, vis2, invAdj, visited);

        for(int j=0; j<n; j++){
            if(vis1[j] && vis2[j]){
                visited[j] = true;
                kingdom[j] = cnt;
            }
        }
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