#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

void solve(){
    int n; cin >> n;
    queue<int> q;
    
    for(int i=1; i<=n; i++)
        q.push(i);

    while(q.size()){
        q.push(q.front());
        q.pop();

        cout << q.front() << " ";
        q.pop();
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
 //   cin >> t;
    while(t--)
        solve();

    return 0;
}