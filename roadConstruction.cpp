#include<bits/stdc++.h>
using namespace std;

class disJointSet{
    vector<int> parent, rank;
    int maxSize, components;

public:
    disJointSet(int n){
        rank.resize(n, 1);
        parent.resize(n);

        for(int i=0; i<n; i++)
            parent[i] = i;
        
        maxSize = 1;
        components = n;
    }

    int findParent(int node){
        if(parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }


    void unite(int x, int y){
        int px = findParent(x);
        int py = findParent(y);

        if(px == py)
            return;

        if(rank[px] < rank[py]){
            rank[py] += rank[px];
            parent[px] = py;
            maxSize = max(maxSize, rank[py]);
        } else {
            rank[px] += rank[py];
            parent[py] = px;
            maxSize = max(maxSize, rank[px]);
        }

        components--;
    }

    int numComponents(){
        return components;
    }

    int largestSize(){
        return maxSize;
    }
};

int main(){
    int n, m;
    cin >> n >> m;

    disJointSet ds(n);

    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;

        ds.unite(u-1, v-1);

        cout << ds.numComponents() << " " << ds.largestSize() << endl;
    }

    return 0;
}