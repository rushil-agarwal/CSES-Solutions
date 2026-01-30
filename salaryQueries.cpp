#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define mod (int)(1e9+7)
using namespace std;

class fenwickTree{
    int n;
    vector<int> bit;

public:

    fenwickTree(int size){
        n = size;
        bit.resize(n+1, 0);
    }

    void update(int idx, int change){
        while(idx <= n){
            bit[idx] += change;
            idx += idx&(-idx);
        }
    }

    int query(int idx){
        int sum=0;
        while(idx > 0){
            sum += bit[idx];
            idx -= idx&(-idx);
        }

        return sum;
    }

    int range(int left, int right){
        return query(right) - query(left-1);
    }
};

int getIndex(vector<ll> &nums, ll value){
    return (lower_bound(nums.begin(), nums.end(), value) - nums.begin() + 1);
}

void solve(){
    int n, q; cin >> n >> q;

    vector<ll> salaries(n), allValues;
    vector<tuple<char, ll, ll>> queries;

    for(int i=0; i<n; i++){
        cin >> salaries[i];
        allValues.push_back(salaries[i]);
    }

    while(q--){
        char type;
        ll a, b; 
        cin >> type >> a >> b;
        queries.push_back({type, a, b});
        if(type == '!'){
            allValues.push_back(b);
        } 
    }


    sort(allValues.begin(), allValues.end());    
    allValues.erase(unique(allValues.begin(), allValues.end()), allValues.end());


    int m= allValues.size();
    fenwickTree fTree(m);

    for(auto &it: salaries){
        int idx = getIndex(allValues, it);
        fTree.update(idx, 1);
    }

    for(auto &[type, a, b]: queries){
        if(type == '!'){
            int old = getIndex(allValues, salaries[a-1]);
            fTree.update(old, -1);
            salaries[a-1] = b;

            int newIdx = getIndex(allValues, b);
            fTree.update(newIdx, 1);
        } else {
            int left = lower_bound(allValues.begin(), allValues.end(), a) - allValues.begin() + 1;
            int right = upper_bound(allValues.begin(), allValues.end(), b) - allValues.begin() + 1 - 1;

            cout << fTree.range(left, right) << "\n";
        }
    }


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