#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<string> grid(n);

    for(int i=0; i<n; i++)
        cin >> grid[i];

    vector<vector<int>> times(n, vector<int>(m, INT_MAX));
    queue<tuple<int, int, int>> q; 
    tuple<int, int, int> start;

    auto isBoundary = [&](int x, int y) -> bool{
        if(x == 0 || y == 0)
            return true;

        if(x == n-1 || y == m-1)
            return true;

        return false;
    };

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 'M')
                q.push({i, j, 0}), times[i][j] = 0;

            if(grid[i][j] == 'A')
                start = {i, j, 0};
        }
    }

    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<char> dirChar = {'D', 'U', 'R', 'L'};

    while(q.size()){
        auto [x, y, time] = q.front(); q.pop();

        for(auto &[dx, dy]: dirs){
            int nx = x+dx, ny = y+dy;

            if(nx < 0 || nx >= n || ny < 0 || ny >= m || times[nx][ny] != INT_MAX || grid[nx][ny] == '#')
                continue;

            times[nx][ny] = time+1;
            q.push({nx, ny, time+1});
        }
    }

    vector<vector<char>> parent(n, vector<char>(m, ' '));
    q.push(start);
    int ex = -1, ey = -1;

    while(q.size()){
        auto [x, y, time] = q.front(); q.pop();

        if(isBoundary(x, y)){
            ex = x, ey = y;
            break;
        }

        for(int i=0; i<4; i++){
            int dx = dirs[i].first, dy = dirs[i].second;
            int nx = x+dx, ny = y+dy;

            if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny] == '#' || time+1 >= times[nx][ny] || parent[nx][ny] != ' ')
                continue;

            parent[nx][ny] = dirChar[i];
            q.push({nx, ny, time+1});
        }
    }

    if(ex == -1){
        cout << "NO" << endl;
        
    } else {
        cout << "YES" << endl;
        string path = "";

        while(ex != get<0>(start) || ey != get<1>(start)){
            char d = parent[ex][ey];
            path+=d;
            if(d == 'U')
                ex++;
            else if(d == 'D')
                ex--;   
            else if(d == 'L')
                ey++;
            else if(d == 'R')
                ey--;   
        }

        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        cout << path << endl;
    }

    return 0;
}