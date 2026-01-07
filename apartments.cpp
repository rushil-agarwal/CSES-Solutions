#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

void solve(){
    int n, m, diff;
    cin >> n >> m >> diff;

    vector<ll> people(n), apartments(m);

    for(int i=0; i<n; i++)
        cin >> people[i];

    for(int i=0; i<m; i++)
        cin >> apartments[i];

    sort(people.begin(), people.end());
    sort(apartments.begin(), apartments.end());

    int i=0, j=0, cnt=0;

    while(i<n && j<m){
        int minSize = people[i] - diff;
        int maxSize = people[i] + diff;

        if(minSize <= apartments[j] && apartments[j] <= maxSize){
            i++;
            j++;
            cnt++;
        } else if(maxSize < apartments[j])
            i++;
        else
            j++;
    }

    cout << cnt << endl;
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    while(t--)
        solve();

    return 0;
}