#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

void solve(){
    int n, q; cin >> n >> q;
    vector<string> forest(n);

    for(int i=0; i<n; i++)
        cin >> forest[i];

    vector<vector<int>> prefix(n, vector<int>(n+1, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            prefix[i][j+1] = prefix[i][j] + (forest[i][j] == '*');
        }
    }

    // for(auto vec: prefix){
    //     for(auto it: vec)
    //         cout << it << " ";
    //     cout << endl;
    // }

    while(q--){
        int cnt=0, x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        x2--;
        y1--;
        y2--;
        
        for(int row = x1; row<=x2; row++){
           // cout << prefix[row][x2] << " " << prefix[row][x1] << endl; 
            cnt += prefix[row][y2+1] - prefix[row][y1];
        }
        cout << cnt << '\n';
        
       // cout << "###########";
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