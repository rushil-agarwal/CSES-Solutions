#include<bits/stdc++.h>
using namespace std;

void dfs(int mask, vector<bool> &visited, int &n){
    visited[mask] = true;

    for(int i=0; i<n; i++){
        if((mask >> i) & 1)
            cout << '1';
        else
            cout << '0';
    }
    cout << endl;

    for(int i=0; i<n; i++){
        int newMask = mask ^ (1<<i);

        if(visited[newMask])
            continue;

        dfs(newMask, visited, n);
    }

}

int main(){
    int n; cin >> n;
    int num = pow(2, n);
    vector<bool> visited(num, false);
    dfs(0, visited, n);

    return 0;
}