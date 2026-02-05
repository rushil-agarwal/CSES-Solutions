#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

int negateNode(int node, int n){
    return (node < n) ? node+n : node-n;
}

void addEdge(vector<vector<int>> &adj, vector<vector<int>> &invAdj, int a, int b, int n){
    adj[negateNode(a, n)].push_back(b);
    adj[negateNode(b, n)].push_back(a);

    invAdj[b].push_back(negateNode(a, n));
    invAdj[a].push_back(negateNode(b, n));
}

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &stk){
    visited[node] = true;

    for(auto it: adj[node]){
        if(!visited[it])
            dfs(it, adj, visited, stk);
    }

    stk.push(node);
}

void dfs2(int node, vector<vector<int>> &invAdj, vector<int> &component, int cnt){
    component[node] = cnt;

    for(auto it: invAdj[node]){
        if(component[it] == -1)
            dfs2(it, invAdj, component, cnt);
    }
}

void solve(){
    int n, m;
    cin >> m >> n;
    
    vector<vector<int>> adj(2*n), invAdj(2*n);

    for(int i=0; i<m; i++){
        char one, two;
        int a, b;
        cin >> one >> a >> two >> b;
        a--;
        b--;

        if(one == '-')
            a += n;
        if(two == '-')
            b += n;

        addEdge(adj, invAdj, a, b, n);
    }

    stack<int> stk;
    vector<bool> visited(2*n, false);

    for(int i=0; i<2*n; i++){
        if(!visited[i])
            dfs(i, adj, visited, stk);
    }

    vector<int> component(2*n, -1);
    int cnt=0;

    while(stk.size()){
        int node = stk.top(); stk.pop();
        if(component[node] != -1)
            continue;

        dfs2(node, invAdj, component, cnt);
        cnt++;
    }

    vector<bool> ans(n, false);

    for(int i=0; i<n; i++){
        if(component[i] == component[negateNode(i, n)]){
            cout << "IMPOSSIBLE\n";
            return;
        }

        ans[i] = component[i] > component[negateNode(i, n)];
    }

    for(int i=0; i<n; i++){
        if(ans[i])
            cout << "+ ";
        else
            cout << "- ";
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
//    cin >> t;
    while(t--)
        solve();

    return 0;
}