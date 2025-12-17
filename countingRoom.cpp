#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int x, int y, vector<string> &map, vector<vector<bool>> &visited){

    visited[x][y] = true;

    for(auto [dx, dy]: dirs){
        int nx = x + dx;
        int ny = y + dy;

        if(nx < 0 || ny < 0 || nx >= map.size() || ny >= map[0].size() || visited[nx][ny] || map[nx][ny] == '#')
            continue;

        dfs(nx, ny, map, visited);
    }
}

int main(){
    int n, m; cin >> n  >> m;
    vector<string> map(n);
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i=0; i<n; i++)
        cin >> map[i];

    int ans = 0;

    queue<pair<int, int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == '.')
                q.push({i, j});
        }
    }

    while(q.size()){
        auto [x, y] = q.front(); q.pop();

        if(visited[x][y])
            continue;
        //cout << x << "  " << y << endl;
        ans++;
        dfs(x, y, map, visited);
    }

    cout << ans << endl;

    return 0;

}