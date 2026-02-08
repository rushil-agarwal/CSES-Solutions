#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &stk){
    visited[node] =true;

    for(auto it: adj[node]){
        if(!visited[it])
            dfs(it, adj, visited, stk);
    }

    stk.push(node);
}

void dfs(int node, vector<vector<int>> &adj, vector<int> &component, int cnt){
    component[node] = cnt;

    for(auto it: adj[node]){
        if(component[it] == 0)
            dfs(it, adj, component, cnt);
    }
}

ll funct(int node, int parent, vector<set<int>> &adj, vector<ll> &scc, vector<ll> &dp){

    if(dp[node] != -1)
        return dp[node];

    ll sum = scc[node];

    for(auto it: adj[node]){
        if(it != parent){
            sum = max(sum, scc[node] + funct(it, node, adj, scc, dp));
        }
    }

    return dp[node] = sum;
}

void solve(){
    int n, m; cin >> n >> m;

    vector<ll> coins(n+1, 0);
    vector<vector<int>> adj(n+1), revAdj(n+1);

    for(int i=1; i<=n; i++)
        cin >> coins[i];

    for(int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }

    stack<int> stk;
    vector<bool> visited(n+1, false);
    
    for(int i=1; i <= n; i++){
        if(!visited[i]){
            dfs(i, adj, visited, stk);
        }
    }

    int cnt=1;
    vector<int> component(n+1, 0);

    while(stk.size()){
        int node = stk.top(); stk.pop();

        if(component[node] != 0)
            continue;

        dfs(node, revAdj, component, cnt);
        cnt++;
    }

    vector<ll> scc(cnt, 0);
    vector<set<int>> newAdj(cnt);

    for(int i=1; i<=n; i++)
        scc[component[i]] += coins[i];

    
    for(int i=1; i<=n; i++){
        for(auto it: adj[i]){
            if(component[i] != component[it])
                newAdj[component[i]].insert(component[it]);
        }
    }

    vector<ll> dp(cnt, -1);
    ll ans = 0;

    for(int i=1; i<cnt; i++){
        if(dp[i] != -1)
            continue;


        ll temp = funct(i, -1, newAdj, scc, dp);;

        ans = max(ans, temp);
    }

    cout << ans << '\n';



}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
  //  cin >> t;
    while(t--)
        solve();

    return 0;
}