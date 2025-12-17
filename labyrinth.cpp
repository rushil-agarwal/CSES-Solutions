#include<bits/stdc++.h>
using namespace std;


void funct(vector<string> &map, int n, int m){
    pair<int, int> start, target;
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> moveDir(n, vector<char>(m));
    bool found = false;
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<char> dirChar = {'D', 'U', 'R', 'L'};

    for(int i=0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(map[i][j] == 'A')
                start= {i, j};
            
            if(map[i][j] == 'B')
                target = {i, j};
        }
    }

    q.push({start.first, start.second});
    visited[start.first][start.second] = true;

    while(!q.empty() && !found){
        auto [x, y] = q.front(); q.pop();

        if(map[x][y] == 'B'){
            found = true;

        }

        for(int i=0; i<4; i++){
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;

            if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] || map[nx][ny] == '#')
                continue;

            visited[nx][ny] = true;
            parent[nx][ny] = {x, y};
            moveDir[nx][ny] = dirChar[i];
            q.push({nx, ny});
        }
    
    }

    if(found){
        string path =  "";
        pair<int, int> curr = target;

        while(curr != start){
            path += moveDir[curr.first][curr.second];

            curr = parent[curr.first][curr.second];
        }

        reverse(path.begin(), path.end());
        cout << "YES\n" << path.length() << endl << path << endl;;
    } else {
        cout << "NO" << endl;
    }
}

int main(){
    int n, m; cin >> n >> m;
    vector<string> map(n);

    for(int i=0; i<n; i++)
        cin >> map[i];

    funct(map, n, m);

    return 0;
}