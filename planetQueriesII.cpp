#include<bits/stdc++.h>
#define ll long long
#define mod (int)(1e9+7)
using namespace std;

int maxBits = 21;

void dfs(int node, vector<int> &length, vector<vector<int>> &sparseTable, vector<bool> &visited){
    if(visited[node])
        return;

    visited[node] = true;

    // process next nodes first to fill the length array
    dfs(sparseTable[node][0], length, sparseTable, visited);

    //steps to enter a loop will be one more than the nxet node
    length[node] = length[sparseTable[node][0]] + 1;
}

int jump(int node, int distance, vector<vector<int>> &sparseTable){
    if(distance <= 0)
        return node; // base case for unreachable nodes

    // performing the jumps
    for(int i=0; i<maxBits; i++){
        if(distance & (1<<i))
            node = sparseTable[node][i];
    }

    return node;
}

void solve(){
    int n, q;
    cin >> n >> q;

    vector<int> arr(n); // the next node array
    vector<int> length(n, 0); // steps to take to enter next cycle 
    vector<vector<int>> sparseTable(n, vector<int>(maxBits, -1)); // binary lifting table
    vector<bool> visited(n, false); // visited array for dfs

    for(int i=0; i<n; i++){
        cin >> arr[i];
        arr[i]--;
        sparseTable[i][0] = arr[i];
    }

    //filling the table
    for(int level = 1; level<maxBits; level++){
        for(int node=0; node<n; node++){
            sparseTable[node][level] = sparseTable[sparseTable[node][level-1]][level-1];
        }
    }

    for(int i=0; i<n; i++){
        if(!visited[i])
            dfs(i, length, sparseTable, visited);
    }

    vector<int> ans;

    //now we process the queries

    for(int i=0; i<q; i++){
        int start, end; cin >> start >> end;
        start--; end--;

        //used in case 2
        int cycleEntryNode = jump(start, length[start], sparseTable);


        //case 1: the end node is on the path of going from start node to entry of a cycle
        //in this on performing difference of their length values much of steps should land at end
        if(jump(start, length[start] - length[end], sparseTable) == end){
            ans.push_back(length[start] - length[end]);
        } else if(jump(cycleEntryNode, length[cycleEntryNode] - length[end], sparseTable) == end){
            // case 2: if end node is in a cycle reachable by start node
            // we find the cycle entry node, and perform jumps, if can reach we return steps + length[start]
            ans.push_back(length[cycleEntryNode] - length[end] + length[start]);
        } else {
            // un reachable node
            ans.push_back(-1);
        }

    }

    for(auto it: ans)
        cout << it << " ";
}

int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    solve();

    return 0;
}