#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pli pair<ll, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

void solve(){
    int n, x; cin >> n >> x;
    vector<pli> vec(n);

    for(int i=0; i<n; i++){
        cin >> vec[i].first;
        vec[i].second = i;
    }

    sort(vec.begin(), vec.end());

    int left = 0, right = n-1;

    while(left < right){
        ll sum = vec[left].first + vec[right].first;

        if(sum == x){{
            cout << vec[left].second + 1 << " " << vec[right].second + 1 << endl;
            return;
        }
        } else if(sum < x)
            left++;
        else
            right--;
    }

    cout << "IMPOSSIBLE" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
   // cin >> t;
    while(t--)
        solve();

    return 0;
}