#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<long long, int, int>
#define mod (int)(1e9+7)
using namespace std;

class disjointSet{
    vector<int> parent, size;
    int n;

public: 
    disjointSet(int x){
        n = x;
        parent.resize(x, 0);
        size.resize(x, 1);

        for(int i=0; i<n; i++)
            parent[i] = i;
    }

    int findParent(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unite(int x, int y){
        int px = findParent(x);
        int py = findParent(y);

        if(px == py)
            return;

        if(size[px] > size[py]){
            size[px] += size[py];
            parent[py] = px;
        } else {
            size[py] += size[px];
            parent[px] = py;
        }
    }
};

void solve(){
    int n, m; cin >> n >> m;
    
    priority_queue<tiii, vector<tiii>, greater<tiii>> pq;

    for(int i=0; i<m; i++){
        int a, b, w; cin >> a >> b >> w;
        a--; b--;

        pq.push({w, a, b});
    }

    int cnt = 0;
    ll ans = 0;
    disjointSet ds(n);

    while(cnt != n-1 && pq.size()){
        auto [weight, a, b] = pq.top(); pq.pop();

        int pa = ds.findParent(a);
        int pb = ds.findParent(b);

        if(pa == pb)
            continue;

        ans += weight;
        ds.unite(a, b);
        cnt++;
    }

    for(int i=1; i<n; i++){
        if(ds.findParent(i) != ds.findParent(0)){
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    cout << ans;

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