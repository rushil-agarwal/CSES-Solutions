#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

void solve(){
    int n; cin >> n;
    vector<string> grid(n);
    for(int i=0; i<n; i++)
        cin >> grid[i];

    string ans;
    vector<vector<bool>> visited(n, vector<bool> (n, false));
    vector<pii> dirs = {{0, 1}, {1, 0}};

    queue<pii> q, store;
    visited[0][0] = true;
    q.push({0,0});
    ans.push_back(grid[0][0]);

    while(q.size()){
        int lvlSize = q.size();
        char minChar = 'Z';
        while(lvlSize--){
            auto [i, j] = q.front(); q.pop();
            store.push({i, j});

            for(auto &[dx, dy]: dirs){
                int ni = i+dx;
                int nj = j+dy;

                if(ni >= n || nj >= n || visited[ni][nj])
                    continue;

                minChar = min(minChar, grid[ni][nj]);
            }   
        }
        
        while(store.size()){
            auto [i, j] = store.front(); store.pop();

            for(auto &[dx, dy]: dirs){
                int ni = i+dx;
                int nj = j+dy;

                if(ni >= n || nj >= n || visited[ni][nj] || grid[ni][nj] != minChar )
                    continue;

                visited[ni][nj] = true;
                q.push({ni, nj});

            }
        }

        ans.push_back(minChar);
    }

    ans.pop_back();

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