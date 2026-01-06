#include<bits/stdc++.h>
#define ll long long
#define mod (int)(1e9+7)
using namespace std;

void dfs(int node, int curr, vector<int> &arr, vector<int> &dp, vector<int> &distance, vector<bool> &visited, int &cycleStart, int &cycleLen){
    if(visited[node])
        return;

    visited[node] = true;
    distance[node] = curr;
    // it stores the distance travelled on current path 


    int next = arr[node];

    if(visited[next]){
        // if visited means we entered a loop
        // if its unset that means it was the start of the loop in current path
        if(dp[next] == 0){
            cycleLen = distance[node] - distance[next] + 1;
            cycleStart = next;
        } else {
            cycleLen = dp[next];
        }
    } else 
        dfs(next, curr+1, arr, dp, distance, visited, cycleStart, cycleLen);

    // if cyclestart is some node, means we are in a loop and dp will store the length of the cycle
    if(cycleStart != -1){
        dp[node] = cycleLen;

        if(node == cycleStart)
            cycleStart = -1;
    } else {
        // if no cycle start then we are on the path and one more step than the next node
        dp[node] = dp[next] + 1;
    }
}

void solve(){
    int n; cin >> n;
    vector<int> arr(n), dp(n, 0), distance(n, 0);
    // arr is the nxet nodes
    // dp stores the answers, if node is in a cycle then length of cycel oetherwise disntace from nearest node in a cycle
    // + length of cycle

    vector<bool> visited(n, false);

    for(int i=0; i<n; i++){
        cin >> arr[i];
        arr[i]--;
    }

    for(int i=0; i<n; i++){
        if(visited[i])
            continue;

        int cycleStart = -1, cycleLen = 0;

        dfs(i, 0, arr, dp, distance, visited, cycleStart, cycleLen);
    }

    for(auto it: dp)
        cout << it << " ";
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1; 
    //cin >> t;
    while(t--)
        solve(), cout << '\n';

    return 0;
}